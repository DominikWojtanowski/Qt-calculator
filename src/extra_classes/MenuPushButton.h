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
    const QString& m_value{};
    void OnClicked();
    QWidget* mainWindow;
public:
    MenuPushButton(const QString & = "");
    MenuPushButton(QWidget *,const QString & = "");
    MenuPushButton(const QString &,const QString & = "");
    MenuPushButton(const QIcon &, const QString & = "",const QString & = "", QWidget * = nullptr);
    void onClicked();
};

#endif