#include "sceneview.hpp"

#include "presenter.hpp"

#include <QScreen>
#include <QRenderAspect>
#include <QInputAspect>
#include <QCamera>
#include <Qt3DRender/QFrameGraph>
#include <Qt3DRender/QForwardRenderer>

#include <memory>

SceneView::SceneView(QWidget * parent, Presenter * presenter)
   : m_presenter(presenter)
{
   m_widget = QWidget::createWindowContainer(&m_view);
   QSize screenSize = m_view.screen()->size();
   m_widget->setMinimumSize(QSize(500, 300));
   m_widget->setMaximumSize(screenSize);
   m_widget->setParent(parent);

   QVariantMap data;
   data.insert(QStringLiteral("surface"), QVariant::fromValue(static_cast<QSurface *>(&m_view)));
   data.insert(QStringLiteral("eventSource"), QVariant::fromValue(&m_view));
   m_engine.setData(data);

   m_engine.registerAspect(new Qt3DRender::QRenderAspect());
   // Create and register engine in charge of user interacton.
   Qt3DInput::QInputAspect *input = new Qt3DInput::QInputAspect();
   m_engine.registerAspect(input);

   // Camera
   std::unique_ptr<Qt3DCore::QCamera> camera(new Qt3DCore::QCamera());
   camera->setObjectName(QStringLiteral("cameraEntity"));
   input->setCamera(camera.get());
   m_cameraHolder.reset(new CameraHolder(camera.get()));

   // Root entity
   std::unique_ptr<Qt3DCore::QEntity> rootEntity(new Qt3DCore::QEntity());

   // FrameGraph
   std::unique_ptr<Qt3DRender::QFrameGraph> frameGraph(new Qt3DRender::QFrameGraph());
   std::unique_ptr<Qt3DRender::QForwardRenderer> forwardRenderer(new Qt3DRender::QForwardRenderer());

   // TechiqueFilter and renderPassFilter are not implement yet
   forwardRenderer->setCamera(camera.get());
   forwardRenderer->setClearColor(Qt::lightGray);

   frameGraph->setActiveFrameGraph(forwardRenderer.release());

   // Setting the FrameGraph
   rootEntity->addComponent(frameGraph.release());

   // Set root object of the scene
   m_engine.setRootEntity(rootEntity.release());
   resetScene();
   resetView();
   camera.release();
}

void SceneView::resetScene() {
  m_bed = m_presenter->loadBed();
  enableBed(true);
}

void SceneView::resetView() {
   m_cameraHolder->resetCamera();
}

void SceneView::enableBed(bool enabled) {
  m_bed->setParent(enabled ? m_engine.rootEntity().data() : Q_NULLPTR);
}

void SceneView::addObject(Qt3DCore::QEntity * entity) {
   entity->setParent(m_engine.rootEntity().data());
}
