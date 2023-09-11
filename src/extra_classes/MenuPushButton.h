#ifndef MENU_PUSH_BUTTON_H
#define MENU_PUSH_BUTTON_H

#include <QtCore/qobject.h>
#include <QtCore/QEvent>
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qsplitter.h>
#include <QtWidgets/qmessagebox.h>
#include <QtGui/QResizeEvent>
#include <iostream>

class MenuPushButton : public QPushButton
{
    Q_OBJECT
private:
    int m_value{};
    void OnClicked();
    QWidget* mainWindow;
public:
    MenuPushButton(int);
    MenuPushButton(QWidget *,int);
    MenuPushButton(const QString &,int);
    MenuPushButton(int, const QIcon &, const QString & = "", QWidget * = nullptr);
    void onClicked();
};

#endif