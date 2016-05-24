#ifndef PREVIEWWIDGET_HPP
#define PREVIEWWIDGET_HPP

#include "presenter.hpp"
#include "sceneview.hpp"

#include <QWidget>

#include <memory>

class PreviewWidget : public QWidget
{
   Q_OBJECT
public:
   explicit PreviewWidget(QWidget *parent = 0);

signals:

public slots:
  void enableBed(bool enabled);
  void resetView();

private:
   std::unique_ptr<Presenter> m_presenter;
   std::unique_ptr<SceneView> m_view;

};

#endif // PREVIEWWIDGET_HPP
