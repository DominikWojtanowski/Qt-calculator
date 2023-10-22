#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtCore>
#include <QtWidgets>
#include <QtGui>

class MainWindow : public QWidget
{
    Q_OBJECT

private:
    using QWidget::QWidget;
public slots:
    void hideSlot(int);
};


#endif // MAIN_WINDOW_H