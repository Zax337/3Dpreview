#ifndef MAINWIDGET_HPP
#define MAINWIDGET_HPP

#include <QWidget>

/*
 * This class represents the main widget, which contains a preview window, a reset button and a checkbox to toggle a virtual bed.
 *
 */
class MainWidget : public QWidget
{
   Q_OBJECT
public:
   explicit MainWidget(QWidget *parent = 0);

signals:

public slots:
private:
};

#endif // MAINWIDGET_HPP
