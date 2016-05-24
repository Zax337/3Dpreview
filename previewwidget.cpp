#include "previewwidget.hpp"

#include <QHBoxLayout>

PreviewWidget::PreviewWidget(QWidget *parent) : QWidget(parent) {

   m_presenter.reset(new Presenter());
   m_view.reset( new SceneView(this, m_presenter.get()));
   QHBoxLayout *hLayout = new QHBoxLayout(this);
   setLayout(hLayout);
   hLayout->addWidget(m_view->widget());

   m_presenter->setView(m_view.get());
}

void PreviewWidget::enableBed(bool enabled) {
   m_presenter->enableBed(enabled);
}

void PreviewWidget::resetView() {
   m_view->resetView();
}
