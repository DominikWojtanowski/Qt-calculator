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
    void OnClicked();
    QWidget* mainWindow;
public:
    MenuPushButton();
    MenuPushButton(QWidget *parent);
    MenuPushButton(const QString &text);
    MenuPushButton(const QIcon &icon, const QString &text = "", QWidget *parent = nullptr);
    void onClicked();
};

#endif