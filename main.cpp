#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>

#include "mainwidget.hpp"
#include "viewer.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWidget widget;
    widget.show();

    return app.exec();
}
