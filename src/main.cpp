#include <iostream>
#include <unordered_map>
#include <vector>
#include <QtCore/qdebug.h>
#include <QtCore/qcoreapplication.h>
#include <QtCore/qobject.h>
#include <QtCore/qfile.h>
#include <QtCore/qtextstream.h>
#include <QtCore/qtimer.h>
#include <QtWidgets/qsplitter.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qapplication.h>
#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlayout.h>
#include <QtWidgets/qgroupbox.h>
#include <QtWidgets/qtoolbutton.h>
#include <QtWidgets/qmenu.h>
#include <QtWidgets/qwidgetaction.h>
#include <QtGui/QResizeEvent>
#include "extra_classes/EventFilter.h"
#include "extra_classes/MenuAction.h"

std::pair<std::string, std::string> make_string_pair(const std::string& value1,const std::string& value2)
{
    return std::make_pair(value1,value2);
}

int main(int argc, char *argv[])
{
    MenuAction *menuAction = new MenuAction(nullptr);
    QApplication app(argc, argv);
    app.setStyleSheet("QApplication::title{background-color:black;}");
    QWidget mainWindow;
    EventFilter *filter = new EventFilter; 
    mainWindow.installEventFilter(filter);
    QString styleSheetPath("css/qstyle.css");
    QFile styleSheetFile(styleSheetPath);
    if (styleSheetFile.open(QFile::ReadOnly | QFile::Text)) {
        QString styleSheetContent = QTextStream(&styleSheetFile).readAll();
        app.setStyleSheet(styleSheetContent);
        styleSheetFile.close();
    } else {
        qDebug() << "Nie mozna otworzyc pliku stylu.";
    }
    mainWindow.setGeometry(0,0,400,630);
    mainWindow.setMinimumHeight(630);
    mainWindow.setMinimumWidth(400);
    mainWindow.setWindowTitle("Kalkulator Qt");
    std::vector<QHBoxLayout*>sub_layouts;
    std::vector<QWidgetAction* >menu_popup_actions;
    std::vector<QLabel*>menu_popup_labels;
    std::vector<QWidget*>Widgets;
    std::vector<MenuAction*>actions;
    std::vector<std::vector<QPushButton*>>Widgets_buttons;
    std::vector<std::vector<std::pair<std::string,std::string>>>menu_popup_labels_texts;
    menu_popup_labels_texts.push_back(
    {
        {"src/ikony/pop_up_menu/calculator.png","   Standardowy"}, // nie wiem dlaczego nie moge dac string(" ",3)??
        {"src/ikony/pop_up_menu/scientific.png","   Naukowy"},
        {"src/ikony/pop_up_menu/graph.png","   Tworzenie wykresow"},
        {"src/ikony/pop_up_menu/programming.png","   Programisty"},
        {"src/ikony/pop_up_menu/calendar.png","   Obliczanie daty"},
    });
    menu_popup_labels_texts.push_back({
        {"src/ikony/pop_up_menu/value.png","   Waluta"},
        {"src/ikony/pop_up_menu/density.png","   Objętość"},
        {"src/ikony/pop_up_menu/length.png","   Długość"},
        {"src/ikony/pop_up_menu/weight.png","   Ciężar i masa"},  
        {"src/ikony/pop_up_menu/temperature.png","   Temperatura"},  
        {"src/ikony/pop_up_menu/energy.png","   Energia"},  
        {"src/ikony/pop_up_menu/area.png","   Powierzchnia"},   
        {"src/ikony/pop_up_menu/speed.png","   Prędkość"},   
        {"src/ikony/pop_up_menu/time.png","   Czas"},   
        {"src/ikony/pop_up_menu/energy.png","   Zasilanie"},
        {"src/ikony/pop_up_menu/data.png","   Dane"}, 
        {"src/ikony/pop_up_menu/cisnienie.png","   Ciśnienie"}, 
        {"src/ikony/pop_up_menu/angle.png","   Kąt"},       
    });
    std::string image_paths[]{"src/ikony/main_app/leave_on_top.png","src/ikony/main_app/history.png"};
    std::string label_texts[]{"Kalkulator","Konwerter"};
    //"ikony/menu_icon.png",



    QVBoxLayout *mainLayout = new QVBoxLayout(&mainWindow);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setAlignment(Qt::AlignTop);

    QSplitter *splitter = new QSplitter(Qt::Horizontal, &mainWindow);
    splitter->setHandleWidth(1);

    //LEFT WIDGET
    Widgets.push_back(new QWidget());
    Widgets.back()->setFixedSize(270, 60);
    Widgets.push_back(new QWidget());
    Widgets.back()->setFixedHeight(60);

    for(const auto& Widget_one : Widgets)
    {
        sub_layouts.push_back(new QHBoxLayout(Widget_one));
        sub_layouts.back()->setSpacing(0);
        sub_layouts.back()->setContentsMargins(0,0,0,0);
        splitter->addWidget(Widget_one);
    }
    sub_layouts[1]->setAlignment(Qt::AlignRight);
        
    Widgets_buttons.push_back({new QPushButton("")});
    //,new QPushButton("")



    Widgets_buttons.push_back({new QPushButton("")});
    filter->setValues(Widgets_buttons[1].back(),splitter);
    int temp_value{};
    for(const auto& buttonArray : Widgets_buttons)
    {
        for(const auto& buttonArrayValue : buttonArray)
        {
            buttonArrayValue->setIcon(QIcon(image_paths[temp_value++].c_str()));
            buttonArrayValue->setObjectName("taskBarMenu");
            buttonArrayValue->setFixedHeight(60);
            buttonArrayValue->setFixedWidth(60);
        }
    }
    /*QObject::connect(Widgets_buttons[0][0],&QPushButton::clicked,[&](){
        QMessageBox::information(&mainWindow,"Kliknieto menu","Kilknieto menu");
    });*/


    QLabel *label = new QLabel("Standardowy");
    label->setFixedSize(170,60);
    label->setContentsMargins(10,0,0,0);
    label->setStyleSheet("font-size:21px;font-weight:500;");
    
    QToolButton* toolbar_menu = new QToolButton();
    QMenu* menu = new QMenu();
    QWidgetAction* menu_label = new QWidgetAction(nullptr);
    toolbar_menu->setFixedSize(60,60);
    toolbar_menu->setObjectName("taskBarMenu");
    toolbar_menu->setIcon(QIcon("src/ikony/main_app/menu_icon.png"));
    toolbar_menu->setPopupMode(QToolButton::InstantPopup);
    toolbar_menu->setMenu(menu);
    toolbar_menu->setStyleSheet("QToolButton::menu-indicator { subcontrol-origin: padding; subcontrol-position: bottom right; image: none; }");
    int value_temp{};
    for(const auto& text : label_texts)
    {
        actions.push_back(new MenuAction(nullptr,"menu_actions"));
        actions.back()->Create_label(text.c_str());
        menu_popup_actions.push_back(actions.back());
        menu->addAction(menu_popup_actions.back());
        if(value_temp<menu_popup_labels_texts.size())
            for(const auto& One_map : menu_popup_labels_texts.at(value_temp))
            {
                actions.push_back(new MenuAction(nullptr,"menu_actions"));
                actions.back()->Create_button_with_icon(QIcon(One_map.first.c_str()),One_map.second.c_str());
                toolbar_menu->menu()->addAction(actions.back());
            }
                
        value_temp++;
    }
    /*menu_label->setDefaultWidget(new QLabel("text"));
    menu->addAction(menu_label);*/
    

    
    sub_layouts[0]->addWidget(toolbar_menu);
    for(int i = 0; i < Widgets_buttons[0].size();i++)
    {
        if(i==Widgets_buttons[0].size()-1)
            sub_layouts[0]->addWidget(label);
        sub_layouts[0]->addWidget(Widgets_buttons[0][i]);
    }
    sub_layouts[1]->addWidget(Widgets_buttons.back().back()); // Nalepsza linijka mojego kodu xD
        
    mainLayout->addWidget(splitter);

    mainWindow.show();  // Wyświetlenie głównego okna

    app.setWindowIcon(QIcon("src/ikony/main_app/kalkulatoricon.png"));

    
    return app.exec();  // Rozpoczęcie głównej pętli aplikacji
}
