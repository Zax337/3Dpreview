#include "mainwidget.hpp"

#include "previewwidget.hpp"

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QCheckBox>
#include <QPushButton>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
  setWindowTitle(QStringLiteral("3D Preview"));
  setMinimumSize(QSize(400, 200));

  QHBoxLayout *hLayout = new QHBoxLayout(this);
  setLayout(hLayout);

  PreviewWidget * preview = new PreviewWidget(this);
  hLayout->addWidget(preview);

  QVBoxLayout * vLayout = new QVBoxLayout();
  hLayout->addLayout(vLayout);


  QCheckBox * bedWidget = new QCheckBox(this);
  bedWidget->setChecked(true);
  bedWidget->setText(QStringLiteral("Toggled Bed"));
  vLayout->addWidget(bedWidget);

  QPushButton * resetWidget = new QPushButton("Reset", this);
  vLayout->addWidget(resetWidget);

  QObject::connect(bedWidget, &QCheckBox::stateChanged, preview, &PreviewWidget::enableBed);
  QObject::connect(resetWidget, &QPushButton::clicked, preview, &PreviewWidget::resetView);

}
