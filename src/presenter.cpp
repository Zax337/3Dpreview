#include "presenter.hpp"

Presenter::Presenter()
   : m_view()
   , m_model(new Model())
{
}

void Presenter::enableBed(bool enable) {
  m_view->enableBed(enable);
}

void Presenter::setView(SceneView *view) {
   m_view = view;
}

Qt3DCore::QEntity * Presenter::loadBed() const {
   return m_model->getBedEntity();
}
