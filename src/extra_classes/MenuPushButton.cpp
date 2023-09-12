#include "MenuPushButton.h"

MenuPushButton::MenuPushButton(std::string info_text) : QPushButton{}, m_value{info_text.substr(3)}
{
    setFixedWidth(310);
    connect(this,&QPushButton::clicked,this,&MenuPushButton::onClicked);
}
MenuPushButton::MenuPushButton(QWidget *parent,std::string info_text) : QPushButton{parent}, mainWindow{parent}, m_value{info_text.substr(3)}
{
    setFixedWidth(310);
    connect(this,&QPushButton::clicked,this,&MenuPushButton::onClicked);
}
MenuPushButton::MenuPushButton(const QString &text,std::string info_text) : QPushButton{text}, m_value{info_text.substr(3)}
{
    setFixedWidth(310);
    connect(this,&QPushButton::clicked,this,&MenuPushButton::onClicked);
}
MenuPushButton::MenuPushButton(const QIcon &icon, const QString &text,std::string info_text, QWidget *parent) : QPushButton{icon,text,parent}, mainWindow{parent}, m_value{info_text.substr(3)}
{
    
    setFixedWidth(310);
    connect(this,&QPushButton::clicked,this,&MenuPushButton::onClicked);
}
void MenuPushButton::onClicked()
{
    QMessageBox::information(mainWindow,"Okienko",m_value.c_str());
}