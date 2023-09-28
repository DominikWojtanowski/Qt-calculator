#ifndef MENU_BUTTON_EVENT_FILTER_H
#define MENU_BUTTON_EVENT_FILTER_H

#include <QtCore/qobject.h>
#include <QtCore/QEvent>
#include <QtCore/qdebug.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qmenu.h>
#include <QtWidgets/qsplitter.h>
#include <QtGui/QResizeEvent>
#include <iostream>
#include <QStyle>

class MenuButtonEventFilter : public QObject
{
public:
    MenuButtonEventFilter(QObject* = nullptr,QMenu* = nullptr);
    void setValues(QPushButton*,QPushButton*);
    void setWidgets(QWidget*, QWidget*);
    void deleteAll();
protected:
    bool eventFilter(QObject*, QEvent*) override;
    void setButtonStyle(QPushButton*,int,const QString&,const QString&);
private:
    bool wasChangedTop = false,wasChangedBottom = false;
    int m_previousWidth,option;
    QPushButton* m_menuButton_top = nullptr;
    QPushButton* m_menuButton_bottom = nullptr;
    QMenu* m_menu = nullptr;
    std::vector<QWidget*>widgets{nullptr,nullptr};
};

#endif // MENU_BUTTON_EVENT_FILTER_H