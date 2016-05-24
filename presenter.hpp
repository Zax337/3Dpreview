#ifndef PRESENTER_HPP
#define PRESENTER_HPP

#include "cameraholder.hpp"
#include "sceneview.hpp"
#include "model.hpp"

#include <memory>

class Presenter
{
public:
   Presenter();
   void setView(SceneView * view);
   void enableBed(bool enable);
   Qt3DCore::QEntity * loadBed() const;
private:
   SceneView * m_view;
   std::unique_ptr<Model> m_model;
};

#endif // PRESENTER_HPP
