#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>

#include "viewer.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget widget;

    widget.setMinimumSize(QSize(400, 200));
    QHBoxLayout *hLayout = new QHBoxLayout(&widget);
    widget.setWindowTitle(QStringLiteral("3D Preview"));
    widget.setLayout(hLayout);

    Viewer preview;
    hLayout->addWidget(preview.getWidget());
    QVBoxLayout * vLayout = new QVBoxLayout();
    hLayout->addLayout(vLayout);
    for(auto widget: preview.getSettingWidgets())
      hLayout->addWidget(widget);

    widget.show();
    return app.exec();
}
