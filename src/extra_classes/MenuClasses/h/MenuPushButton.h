#ifndef MENU_PUSH_BUTTON_H
#define MENU_PUSH_BUTTON_H

#include <QtCore/qobject.h>
#include <QtCore/QEvent>
#include <QtCore/qdebug.h>
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
    std::string m_value{};
    void OnClicked();
    QWidget* mainWindow;
public:
    MenuPushButton(std::string = "");
    MenuPushButton(QWidget *,std::string = "");
    MenuPushButton(const QString &,std::string = "");
    MenuPushButton(const QIcon &, const QString & = "",std::string = "", QWidget * = nullptr);
    void onClicked();
};

#endif