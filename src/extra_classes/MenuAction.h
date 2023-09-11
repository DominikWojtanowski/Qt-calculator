#ifndef MENU_ACTION_H
#define MENU_ACTION_H

#include <QtWidgets/QWidgetAction>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMessageBox>
#include <QtGui/QIcon>
#include "MenuPushButton.h"


class MenuAction : public QWidgetAction {
    Q_OBJECT
private:
    MenuPushButton* m_menuButton = nullptr;
    QLabel* m_menuLabel = nullptr;
    QIcon* m_menuIcon = nullptr;
    QWidget* m_mainWindow = nullptr;
    QString m_objectName{};
public:
    MenuAction(QWidget* = nullptr,const QString& = "");
    void Create_button(const QString& = "",int = 0);
    void Create_button_with_icon(const QIcon&, const QString& = "",int = 0);
    void Create_label(const QString& = "");
    // void Create_label_with_icon(const QIcon&, const QString& = ""); nie widze zeby bylo potrzebne
    void on_Clicked();
};

#endif
