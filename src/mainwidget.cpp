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

  // Preview window
  PreviewWidget * preview = new PreviewWidget(this);
  hLayout->addWidget(preview);

  QVBoxLayout * vLayout = new QVBoxLayout();
  hLayout->addLayout(vLayout);

  // Virtual bed
  QCheckBox * bedWidget = new QCheckBox(this);
  bedWidget->setChecked(true);
  bedWidget->setText(QStringLiteral("Toggled Bed"));
  vLayout->addWidget(bedWidget);

  // Reset button
  QPushButton * resetWidget = new QPushButton("Reset", this);
  vLayout->addWidget(resetWidget);

  // Connect the virtual bed checkbox to the preview.
  QObject::connect(bedWidget, &QCheckBox::stateChanged, preview, &PreviewWidget::enableBed);
  // Connect the reset button to the preview.
  QObject::connect(resetWidget, &QPushButton::clicked, preview, &PreviewWidget::resetView);

}
