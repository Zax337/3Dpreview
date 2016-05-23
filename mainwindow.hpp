#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QWindow>

class MainWindow : public QWindow
{
   Q_OBJECT
public:
   explicit MainWindow(QScreen *screen = 0);

protected:
    virtual void keyPressEvent(QKeyEvent *e);

signals:

public slots:
};

#endif // MAINWINDOW_HPP
