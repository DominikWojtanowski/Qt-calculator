#include <iostream>
#include <vector>
#include <QtCore>
#include <QtWidgets>
#include <QtGui>
#include "extra_classes/EventFilter.h"
#include "extra_classes/MenuAction.h"
#include "extra_classes/SpecialButton.h"
#include "extra_classes/MenuButtonEventFilter.h"
#include "extra_classes/Shadow_Widget.h"

std::pair<std::string, std::string> make_string_pair(const std::string& value1,const std::string& value2)
{
    return std::make_pair(value1,value2);
}

int main(int argc, char *argv[])
{
    int menu_value{};
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
    mainWindow.setGeometry(0,0,400,588);
    mainWindow.setMinimumHeight(588);
    mainWindow.setMinimumWidth(400);
    mainWindow.setWindowTitle("Kalkulator Qt");
    bool show = false;
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

    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect;
    shadowEffect->setBlurRadius(5); // Ustawienie promienia rozmycia cienia
    shadowEffect->setColor(QColor(111, 111, 111,255)); // Ustawienie koloru cienia (RGBA)
    shadowEffect->setOffset(2, 7);

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
    
    QLabel *label = new QLabel("Standardowy");
    label->setFixedSize(170,60);
    label->setContentsMargins(10,0,0,0);
    label->setStyleSheet("font-size:21px;font-weight:500;");
    
    QToolButton* toolbar_menu = new QToolButton();
    QMenu* menu = new QMenu(toolbar_menu);
    QWidgetAction* menu_label = new QWidgetAction(nullptr);
    toolbar_menu->setFixedSize(60,60);
    toolbar_menu->setObjectName("taskBarMenu");
    toolbar_menu->setIcon(QIcon("src/ikony/main_app/menu_icon.png"));
    toolbar_menu->setMenu(menu);
    toolbar_menu->setStyleSheet("QToolButton::menu-indicator { subcontrol-origin: padding; subcontrol-position: bottom right; image: none; }");
    int value_temp{};
    int numbers{};
    
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
                actions.back()->Create_button_with_icon(QIcon(One_map.first.c_str()),One_map.second.c_str(),One_map.second.c_str());
                toolbar_menu->menu()->addAction(actions.back());
            }
        value_temp++;
    }

    Shadow_Widget* animationSpecialWidget = new Shadow_Widget(shadowEffect,&mainWindow);
    animationSpecialWidget->setVisible(false);
    SpecialButton* b1 = new SpecialButton(&mainWindow);
    b1->setObjectName("taskBarMenu");
    b1->setFixedSize(60,60);
    b1->setIcon(QIcon("src/ikony/main_app/menu_icon.png"));
    animationSpecialWidget->setStyleSheet("background-color:rgb(231,231,231);border-top-right-radius: 17px;");

    QPropertyAnimation *animation = new QPropertyAnimation(menu, "geometry");
    QPropertyAnimation *animation2 = new QPropertyAnimation(animationSpecialWidget, "geometry");

    QRect secondStartSize(QRect(0, 0, 0, 60));
    QRect secondEndSize(QRect(0, 0, 317, 60));

    MenuButtonEventFilter* specialFilter = new MenuButtonEventFilter();
    specialFilter->setValues(b1);

    QObject::connect(b1,&QToolButton::clicked,b1,[&](){
        QPoint pos = toolbar_menu->mapToGlobal(toolbar_menu->rect().bottomLeft());
        pos.setY(pos.y());
        QRect startSize(pos, QSize(0, menu->sizeHint().height()));
        QRect endSize(QRect(pos, QSize(menu->sizeHint().width(), menu->sizeHint().height())));

        
        
        
          
        if(!show)
        {
            menu->installEventFilter(specialFilter);
            show = true;
            animationSpecialWidget->setVisible(true);

            animation->setDuration(140);
            animation->setStartValue(startSize);
            animation->setEndValue(endSize);

            animation2->setDuration(140);
            animation2->setStartValue(secondStartSize); // Rozmiar początkowy
            animation2->setEndValue(secondEndSize);

            menu->setFixedHeight(mainWindow.size().height()-128);
            animation->start();
            animation2->start();
            menu->exec();
        }
        else
        {
            b1->setObjectName("taskBarMenu");
            menu->removeEventFilter(specialFilter);
            show = false;

            animation->setDuration(240);
            animation->setStartValue(endSize);
            animation->setEndValue(startSize);

            animation2->setDuration(140);
            animation2->setStartValue(secondEndSize); // Rozmiar początkowy
            animation2->setEndValue(secondStartSize);

            animation->start();
            animation2->start();
        }
    });
    
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
