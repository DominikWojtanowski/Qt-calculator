#include "MenuAction.h"


MenuAction::MenuAction(QWidget* parent ,const QString& objectName) : QWidgetAction{parent}, m_objectName{objectName}, m_mainWindow{parent}
{}
void MenuAction::Create_button(const QString& button_text,const std::string& info_text) {
    m_menuButton = new MenuPushButton(button_text,info_text);
    m_menuButton->setObjectName(m_objectName);
    this->setDefaultWidget(m_menuButton);
}
void MenuAction::Create_button_with_icon(const QIcon& icon,const QString& button_text,const std::string& info_text) {
    m_menuButton = new MenuPushButton(icon,button_text,info_text);
    m_menuButton->setObjectName(m_objectName);
    this->setDefaultWidget(m_menuButton);
}
void MenuAction::Create_label(const QString& label_text) {
    m_menuLabel = new QLabel(label_text);
    m_menuLabel->setObjectName(m_objectName);
    this->setDefaultWidget(m_menuLabel);
}
void MenuAction::on_Clicked()
{
    QMessageBox::information(m_mainWindow,"Akcja zostala kliknieta","akcja");
}
