#ifndef SCENEVIEW_HPP
#define SCENEVIEW_HPP

#include "mainwindow.hpp"
#include "cameraholder.hpp"

#include <QAspectEngine>
#include <QWidget>

#include <memory>

class Presenter;

class SceneView {
public:
   SceneView(QWidget * parent, Presenter * presenter);
   QWidget * widget() { return m_widget;}
   void resetView();
   void enableBed(bool enabled);

   void addObject(Qt3DCore::QEntity * entity);

private:
   void resetScene();
   Presenter * m_presenter;
   std::unique_ptr<CameraHolder> m_cameraHolder;
   Qt3DCore::QAspectEngine m_engine;
   MainWindow m_view;
   QWidget * m_widget;
   Qt3DCore::QEntity * m_bed;
};

#endif // SCENEVIEW_HPP
