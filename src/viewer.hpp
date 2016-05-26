#ifndef VIEWER_HPP
#define VIEWER_HPP

#include <QWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QPushButton>
#include <Qt3DCore/qaspectengine.h>
#include <Qt3DCore/qcamera.h>
#include "mainwindow.hpp"
#include "transformer.hpp"
#include "cameraholder.hpp"

class Viewer
{
public:
   explicit Viewer();
   QWidget * getWidget() { return m_widget;}
   std::vector<QWidget *> getSettingWidgets() { return {m_bedWidget, m_resetWidget};}

signals:

public slots:
   void resetView();

private:
   MainWindow m_view;
   QWidget * m_widget;
   QCheckBox * m_bedWidget;
   QPushButton * m_resetWidget;

   Qt3DCore::QAspectEngine m_engine;

   Transformer m_transformer;
   CameraHolder m_cameraHolder;
};

#endif /* VIEWER_HPP */
