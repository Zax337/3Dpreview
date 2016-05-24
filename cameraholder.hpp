#ifndef CAMERAHOLDER_HPP
#define CAMERAHOLDER_HPP

#include <QObject>
#include <Qt3DCore/QCamera>

class CameraHolder: public QObject
{
   Q_OBJECT
public:
   CameraHolder(Qt3DCore::QCamera * camera);
   void resetCamera();

private:
   Qt3DCore::QCamera * m_camera;
};

#endif // CAMERAHOLDER_HPP
