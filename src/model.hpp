#ifndef MODEL_HPP
#define MODEL_HPP

#include <QObject>
#include <Qt3DCore/QEntity>
#include <Qt3DRender/QPhongMaterial>

class Model
{
public:
   Model();
   Qt3DCore::QEntity * getBedEntity() const;
private:
   QWeakPointer<Qt3DCore::QEntity> m_rootEntity;
   Qt3DCore::QEntity * m_bed;
   Qt3DRender::QPhongMaterial * m_material;
};

#endif // MODEL_HPP
