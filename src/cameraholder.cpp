#include "cameraholder.hpp"
#include <QCameraLens>

CameraHolder::CameraHolder(Qt3DCore::QCamera * camera):
   m_camera(camera)
{}

void CameraHolder::resetCamera() {
   m_camera->setProjectionType(Qt3DCore::QCameraLens::PerspectiveProjection);
   m_camera->setPosition(QVector3D(0.0f, 10.0f, -60.0f));
   m_camera->setUpVector(QVector3D(0, 1, 0));
   m_camera->setViewCenter(QVector3D(0, 10, 10));
}
