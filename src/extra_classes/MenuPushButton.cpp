#include "MenuPushButton.h"

MenuPushButton::MenuPushButton(const QString &info_text) : QPushButton{}, m_value{info_text}
{
    setFixedWidth(310);
    connect(this,&QPushButton::clicked,this,&MenuPushButton::onClicked);
}
MenuPushButton::MenuPushButton(QWidget *parent,const QString &info_text) : QPushButton{parent}, mainWindow{parent}, m_value{info_text}
{
    setFixedWidth(310);
    connect(this,&QPushButton::clicked,this,&MenuPushButton::onClicked);
}
MenuPushButton::MenuPushButton(const QString &text,const QString &info_text) : QPushButton{text}, m_value{info_text}
{
    setFixedWidth(310);
    connect(this,&QPushButton::clicked,this,&MenuPushButton::onClicked);
}
MenuPushButton::MenuPushButton(const QIcon &icon, const QString &text,const QString& info_text, QWidget *parent) : QPushButton{icon,text,parent}, mainWindow{parent}, m_value{info_text}
{
    setFixedWidth(310);
    connect(this,&QPushButton::clicked,this,&MenuPushButton::onClicked);
}
void MenuPushButton::onClicked()
{
    QMessageBox::information(mainWindow,"Okienko",m_value);
}