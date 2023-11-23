#include "ListClasses/h/MenuList.h"

MenuList::MenuList(MainWindow *parent): QListWidget(parent), mainWindow{parent}{
        
        qApp->installEventFilter(this);
        QObject::connect(this,SIGNAL(listHidden(int,int)),parent,SLOT(hideSlot(int,int)));
    }
bool MenuList::eventFilter(QObject *watched, QEvent *event)
{
    
    if (event->type() == QEvent::MouseButtonPress) {
        if (watched != this && QCursor::pos().x() > 327) {
            QMouseEvent* event2 = reinterpret_cast<QMouseEvent*>(event);
            emit listHidden(event2->pos().x(),event2->pos().y());
        }
    }
    return false;
}