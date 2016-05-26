#include "mainwindow.hpp"
#include <QOpenGLContext>
#include <QKeyEvent>
#include <QGuiApplication>

MainWindow::MainWindow(QScreen * screen) : QWindow(screen)
{
       setSurfaceType(QSurface::OpenGLSurface);

       resize(1024, 768);

       QSurfaceFormat format;
       if (QOpenGLContext::openGLModuleType() == QOpenGLContext::LibGL) {
           format.setVersion(4, 3);
           format.setProfile(QSurfaceFormat::CoreProfile);
       }
       format.setDepthBufferSize( 24 );
       format.setSamples( 4 );
       format.setStencilBufferSize(8);
       setFormat(format);
       create();
}

void MainWindow::keyPressEvent( QKeyEvent* e ) {
    switch ( e->key() )
    {
        case Qt::Key_Escape:
            QGuiApplication::quit();
            break;

        default:
            QWindow::keyPressEvent( e );
    }
}