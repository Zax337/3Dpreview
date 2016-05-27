#include "model.hpp"

#include <Qt3DRender/qplanemesh.h>
#include <Qt3DRender/qcylindermesh.h>
#include <Qt3DCore/qtransform.h>

#include <memory>

Model::Model()
   : m_bed(new Qt3DCore::QEntity())
{

   // Create a Plan mesh to represents a virtual bed.
   std::unique_ptr<Qt3DRender::QPlaneMesh> plan(new Qt3DRender::QPlaneMesh());
   plan->setWidth(20.0f);
   plan->setHeight(20.0f);
   plan->setMeshResolution(QSize(20,20));
   m_bed->addComponent(plan.release());

   // Add some material details to it.
   std::unique_ptr<Qt3DRender::QPhongMaterial> material(new Qt3DRender::QPhongMaterial());
   material->setAmbient(Qt::red);
   material->setDiffuse(Qt::red);
   material->setSpecular(Qt::black);
   material->setEnabled(true);
   m_bed->addComponent(material.release());
}

Qt3DCore::QEntity * Model::getBedEntity() const {
    return m_bed;
}
