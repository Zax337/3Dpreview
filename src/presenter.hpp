#ifndef PRESENTER_HPP
#define PRESENTER_HPP

#include "cameraholder.hpp"
#include "sceneview.hpp"
#include "model.hpp"

#include <memory>

/*
 * This class' purpose is to perform business logic and update the UI accordingly.
 * Instances don't get the ownership over the view they modify.
 */
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
