#include "viewer.hpp"
#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qcameralens.h>

#include <Qt3DInput/QInputAspect>

#include <Qt3DRender/qtechnique.h>
#include <Qt3DRender/qmaterial.h>
#include <Qt3DRender/qeffect.h>
#include <Qt3DRender/qtexture.h>
#include <Qt3DRender/qrenderpass.h>

#include <Qt3DCore/qaspectengine.h>

#include <Qt3DRender/qrenderaspect.h>
#include <Qt3DRender/qframegraph.h>
#include <Qt3DRender/qforwardrenderer.h>
#include <QScreen>
#include <QSurface>
#include <QWindow>

using namespace Qt3DCore;

Viewer::Viewer()
{
   m_widget = QWidget::createWindowContainer(&m_view);
   QSize screenSize = m_view.screen()->size();
   m_widget->setMinimumSize(QSize(500, 300));
   m_widget->setMaximumSize(screenSize);

   QVariantMap data;
   data.insert(QStringLiteral("surface"), QVariant::fromValue(static_cast<QSurface *>(&m_view)));
   data.insert(QStringLiteral("eventSource"), QVariant::fromValue(&m_view));
   m_engine.setData(data);

   // Root entity
   Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity();

   auto render = new Qt3DRender::QRenderAspect();
   m_engine.registerAspect(render);
   Qt3DInput::QInputAspect *input = new Qt3DInput::QInputAspect();
   m_engine.registerAspect(input);

   // Camera
   Qt3DCore::QCamera * camera = new Qt3DCore::QCamera();
   camera->setParent(rootEntity);
   camera->setObjectName(QStringLiteral("cameraEntity"));
   input->setCamera(camera);
   m_cameraHolder.setCamera(camera);

   // FrameGraph
   Qt3DRender::QFrameGraph *frameGraph = new Qt3DRender::QFrameGraph();
   Qt3DRender::QForwardRenderer *forwardRenderer = new Qt3DRender::QForwardRenderer();

   // TechiqueFilter and renderPassFilter are not implement yet
   forwardRenderer->setCamera(camera);
   forwardRenderer->setClearColor(Qt::lightGray);

   frameGraph->setActiveFrameGraph(forwardRenderer);

   // Setting the FrameGraph
   rootEntity->addComponent(frameGraph);

   // Set root object of the scene
   m_engine.setRootEntity(rootEntity);
   m_transformer.setRootEntity(m_engine.rootEntity());


   m_bedWidget = new QCheckBox();
   m_bedWidget->setChecked(true);
   m_bedWidget->setText(QStringLiteral("Toggled Bed"));

   QObject::connect(m_bedWidget, &QCheckBox::stateChanged,
                    &m_transformer, &Transformer::enableBed);

   m_resetWidget = new QPushButton("Reset");
   QObject::connect(m_resetWidget, &QPushButton::clicked, &m_cameraHolder, &CameraHolder::resetCamera);

}
