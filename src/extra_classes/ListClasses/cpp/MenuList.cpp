#include "ListClasses/h/MenuList.h"

MenuList::MenuList(MainWindow *parent): QListWidget(parent), mainWindow{parent}{
        // Przechwytujemy zdarzenia myszy poza obszarem listy
        qApp->installEventFilter(this);
        QObject::connect(this,SIGNAL(listHidden(int)),parent,SLOT(hideSlot(int)));
    }
bool MenuList::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        if (watched != this && QCursor::pos().x() > 327) {
            emit listHidden(10);
        }
    }
    return false;
}