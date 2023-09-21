#ifndef MENU_BUTTON_EVENT_FILTER_H
#define MENU_BUTTON_EVENT_FILTER_H

#include <QtCore/qobject.h>
#include <QtCore/QEvent>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qsplitter.h>
#include <QtGui/QResizeEvent>
#include <iostream>

class MenuButtonEventFilter : public QObject
{
public:
    MenuButtonEventFilter(QObject* = nullptr);
    void setValues(QPushButton*);
    void deleteAll();
protected:
    bool eventFilter(QObject*, QEvent*) override;
private:
    bool wasChanged = false;
    int m_previousWidth;
    QPushButton* m_history = nullptr;
};

#endif // MENU_BUTTON_EVENT_FILTER_H