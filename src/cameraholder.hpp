#ifndef CAMERAHOLDER_HPP
#define CAMERAHOLDER_HPP

#include <QObject>
#include <Qt3DCore/QCamera>

/*
 * This class holds a camera and is in charge of its settings.
 * Instances don't get the ownership over the Qt representation.
 */
class CameraHolder: public QObject
{
   Q_OBJECT
public:
   CameraHolder(Qt3DCore::QCamera * camera);
   /*
    * Call this method to reset the camera to its default settings.
    */
   void resetCamera();

private:
   Qt3DCore::QCamera * m_camera;
};

#endif // CAMERAHOLDER_HPP
