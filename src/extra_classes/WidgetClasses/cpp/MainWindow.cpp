#include "WidgetClasses/h/MainWindow.h"

void MainWindow::hideSlot(int value)
{
    qDebug() << "Dziala?";
    QMouseEvent *mouseEvent = new QMouseEvent(QEvent::MouseButtonPress, QPoint(328,0), Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
}