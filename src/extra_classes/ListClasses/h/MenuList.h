#ifndef MENU_LIST_H
#define MENU_LIST_H

#include "WidgetClasses/h/MainWindow.h"

class MenuList : public QListWidget
{
    Q_OBJECT

public:
    MenuList(MainWindow* = nullptr);
protected:
    bool eventFilter(QObject*, QEvent*) override;
private:
    MainWindow* mainWindow = nullptr; 
signals:
    void listHidden(int);


};


#endif