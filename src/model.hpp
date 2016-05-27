#ifndef MODEL_HPP
#define MODEL_HPP

#include <QObject>
#include <Qt3DCore/QEntity>
#include <Qt3DRender/QPhongMaterial>

/*
 * This class' purpose is to access content.
 */
class Model
{
public:
   Model();
   Qt3DCore::QEntity * getBedEntity() const;
private:
   Qt3DCore::QEntity * m_bed;
};

#endif // MODEL_HPP
