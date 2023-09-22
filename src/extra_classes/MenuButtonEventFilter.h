#ifndef MENU_BUTTON_EVENT_FILTER_H
#define MENU_BUTTON_EVENT_FILTER_H

#include <QtCore/qobject.h>
#include <QtCore/QEvent>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qmenu.h>
#include <QtWidgets/qsplitter.h>
#include <QtGui/QResizeEvent>
#include <iostream>

class MenuButtonEventFilter : public QObject
{
public:
    MenuButtonEventFilter(QObject* = nullptr,QMenu* = nullptr);
    void setValues(QPushButton*);
    void deleteAll();
protected:
    bool eventFilter(QObject*, QEvent*) override;
private:
    bool wasChanged = false;
    int m_previousWidth;
    QPushButton* m_history = nullptr;
    QMenu* m_menu = nullptr;
};

#endif // MENU_BUTTON_EVENT_FILTER_H