#include "MenuPushButton.h"

MenuPushButton::MenuPushButton(int value) : QPushButton{}, m_value{value}
{
    setFixedWidth(310);
    connect(this,&QPushButton::clicked,this,&MenuPushButton::onClicked);
}
MenuPushButton::MenuPushButton(QWidget *parent,int value) : QPushButton{parent}, mainWindow{parent}, m_value{value}
{
    setFixedWidth(310);
    connect(this,&QPushButton::clicked,this,&MenuPushButton::onClicked);
}
MenuPushButton::MenuPushButton(const QString &text,int value) : QPushButton{text}, m_value{value}
{
    setFixedWidth(310);
    connect(this,&QPushButton::clicked,this,&MenuPushButton::onClicked);
}
MenuPushButton::MenuPushButton(int value,const QIcon &icon, const QString &text, QWidget *parent) : QPushButton{icon,text,parent}, mainWindow{parent}, m_value{value}
{
    setFixedWidth(310);
    connect(this,&QPushButton::clicked,this,&MenuPushButton::onClicked);
}
void MenuPushButton::onClicked()
{
    QMessageBox::information(mainWindow,"Okienko",std::to_string(m_value).c_str());
}