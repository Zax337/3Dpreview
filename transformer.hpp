#ifndef TRANSFORMER_HPP
#define TRANSFORMER_HPP

#include <QObject>
#include <Qt3DCore/QEntity>
#include <Qt3DRender/QPhongMaterial>

class Transformer : public QObject
{
   Q_OBJECT
public:
   Transformer();
   void setRootEntity(QSharedPointer<Qt3DCore::QEntity> rootEntity);

signals:

public slots:
  void enableBed(bool enabled);
  void toto() {}
  void resetView();

private:
//   QSharedPointer<Qt3DCore::QEntity> m_rootEntity;
   QWeakPointer<Qt3DCore::QEntity> m_rootEntity;
   Qt3DCore::QEntity * m_bed;
   Qt3DRender::QPhongMaterial * m_material;
};

#endif // TRANSFORMER_HPP
