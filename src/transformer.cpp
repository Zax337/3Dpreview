#include "transformer.hpp"

#include <Qt3DRender/qplanemesh.h>
#include <Qt3DRender/qcylindermesh.h>
#include <Qt3DCore/qtransform.h>

void Transformer::setRootEntity(QSharedPointer<Qt3DCore::QEntity> rootEntity) {
   m_rootEntity = rootEntity.toWeakRef();
   m_bed->setParent(rootEntity.data());
}

Transformer::Transformer()
   : m_bed(new Qt3DCore::QEntity())
{
   Qt3DRender::QPlaneMesh * cube = new Qt3DRender::QPlaneMesh();
   cube->setWidth(20.0f);
   cube->setHeight(20.0f);
   cube->setMeshResolution(QSize(20,20));
   m_bed->addComponent(cube);

   Qt3DCore::QTransform *cylinderTransform = new Qt3DCore::QTransform;
   cylinderTransform->setScale(1.0f);
   cylinderTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1, 0, 0), 90.0f));
   cylinderTransform->setTranslation(QVector3D{0,0,10});

   m_material = new Qt3DRender::QPhongMaterial();
   m_material->setAmbient(Qt::red);
   m_material->setDiffuse(Qt::red);
   m_material->setSpecular(Qt::black);
   m_material->setEnabled(true);

   m_bed->addComponent(m_material);
}

void Transformer::enableBed(bool enabled) {
    QSharedPointer<Qt3DCore::QEntity> rootEntity = m_rootEntity.lock();
    if( nullptr != rootEntity.data()) {
      m_bed->setParent(enabled ? rootEntity.data() : Q_NULLPTR);
    }
}

void Transformer::resetView() {}
