#include "MenuPushButton.h"

MenuPushButton::MenuPushButton() : QPushButton{}
{
    setFixedWidth(310);
    connect(this,&QPushButton::clicked,this,&MenuPushButton::onClicked);
}
MenuPushButton::MenuPushButton(QWidget *parent) : QPushButton{parent}, mainWindow{parent}
{
    setFixedWidth(310);
    connect(this,&QPushButton::clicked,this,&MenuPushButton::onClicked);
}
MenuPushButton::MenuPushButton(const QString &text) : QPushButton{text}
{
    setFixedWidth(310);
    connect(this,&QPushButton::clicked,this,&MenuPushButton::onClicked);
}
MenuPushButton::MenuPushButton(const QIcon &icon, const QString &text, QWidget *parent) : QPushButton{icon,text,parent}, mainWindow{parent}
{
    setFixedWidth(310);
    connect(this,&QPushButton::clicked,this,&MenuPushButton::onClicked);
}
void MenuPushButton::onClicked()
{
    QMessageBox::information(mainWindow,"Okienko","Klikniete okienko");
}