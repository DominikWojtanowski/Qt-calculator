#include <iostream>
#include <vector>
#include <QtCore>
#include <QtWidgets>
#include <QtGui>
//ENUMS

#include "extra_classes/Language/h/Language.h"

//MY CLASSES
#include "extra_classes/EventFilters/h/EventFilter.h"
#include "extra_classes/WidgetClasses/h/Shadow_Widget.h"
#include "extra_classes/ButtonClasses/h/SpecialButton.h"
#include "extra_classes/ButtonClasses/h/ButtonWithSlot.h"
#include "extra_classes/Signals_Slots/Emitters/h/Emitter.h"

std::pair<std::string, std::string> make_string_pair(const std::string& value1,const std::string& value2)
{
    return std::make_pair(value1,value2);
}

int main(int argc, char *argv[])
{
    bool isLabel{false};
    int menu_value{},which_icon_index{},which_actions_index{};
    std::vector<QHBoxLayout*>sub_layouts;
    std::vector<QWidgetAction* >menu_popup_actions;
    std::vector<QLabel*>menu_popup_labels;
    std::vector<QWidget*>Widgets;
    std::vector<std::vector<ButtonWithSlot*>>Widgets_buttons;
    std::vector<std::vector<std::pair<QString,QString>>>menu_popup_labels_texts;
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
    
    QApplication app(argc, argv);
    
    app.setWindowIcon(QIcon("src/ikony/main_app/kalkulatoricon.png"));
    QWidget mainWindow;
    QString styleSheetPath("css/qstyle.css");
    QFile styleSheetFile(styleSheetPath);
    if (styleSheetFile.open(QFile::ReadOnly | QFile::Text)) {
        QString styleSheetContent = QTextStream(&styleSheetFile).readAll();
        app.setStyleSheet(styleSheetContent);
        styleSheetFile.close();
    } else {
        qDebug() << "Nie mozna otworzyc pliku stylu.";
    }
    EventFilter *filter = new EventFilter;
    Emitter* emitter = new Emitter;
    

    mainWindow.installEventFilter(filter);
    
    mainWindow.setGeometry(0,0,400,588);
    mainWindow.setMinimumHeight(588);
    mainWindow.setMinimumWidth(400);
    mainWindow.setWindowTitle("Kalkulator Qt");
    
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect;
    shadowEffect->setBlurRadius(5); // Ustawienie promienia rozmycia cienia
    shadowEffect->setColor(QColor(111, 111, 111,255)); // Ustawienie koloru cienia (RGBA)
    shadowEffect->setOffset(2, 5.5);
    QGraphicsDropShadowEffect *listEffect = new QGraphicsDropShadowEffect;
    listEffect->setBlurRadius(5); // Ustawienie promienia rozmycia cienia
    listEffect->setColor(QColor(111, 111, 111,255)); // Ustawienie koloru cienia (RGBA)
    listEffect->setOffset(2,5);
    QGraphicsDropShadowEffect* nextEffect = new QGraphicsDropShadowEffect();
    nextEffect->setBlurRadius(5); // Ustawienie promienia rozmycia cienia
    nextEffect->setColor(QColor(111, 111, 111,255)); // Ustawienie koloru cienia (RGBA)
    nextEffect->setOffset(2, 2);

    QVBoxLayout *masterLayout = new QVBoxLayout(&mainWindow);
    masterLayout->setSpacing(0);
    masterLayout->setContentsMargins(0,0,0,0);
    masterLayout->setAlignment(Qt::AlignTop);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setAlignment(Qt::AlignTop);

    QSplitter *splitter = new QSplitter(Qt::Horizontal, &mainWindow);
    splitter->setHandleWidth(1);
    splitter->setChildrenCollapsible(false);
    
    

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
    Widgets_buttons.push_back({new ButtonWithSlot("")});

    Widgets_buttons.push_back({new ButtonWithSlot("")});

    QObject::connect(emitter, SIGNAL(customSignal(int)), Widgets_buttons.back().back(), SLOT(customSlot(int)));
    
    for(const auto& buttonArray : Widgets_buttons)
    {
        for(const auto& buttonArrayValue : buttonArray)
        {
            QIcon icon;
            icon.addPixmap(QPixmap(image_paths[which_icon_index].c_str()), QIcon::Normal);
            icon.addPixmap(QPixmap(image_paths[which_icon_index++].c_str()), QIcon::Disabled);
            buttonArrayValue->setIcon(icon);
            buttonArrayValue->setObjectName("taskBarMenu");
            buttonArrayValue->setFixedHeight(60);
            buttonArrayValue->setFixedWidth(60);
        }
    }
    
    QLabel *label = new QLabel("Standardowy");
    label->setFixedSize(170,60);
    label->setContentsMargins(10,0,0,0);
    label->setStyleSheet("font-size:21px;font-weight:500;");
    
    QListWidget listWidget(&mainWindow);
    listWidget.setGraphicsEffect(listEffect);
    listWidget.setObjectName("Default");
    listWidget.setVisible(false);
    listWidget.setFocusPolicy(Qt::NoFocus);
    listWidget.hide();
    
    for(int i = 0; i < sizeof(label_texts) / sizeof(label_texts[0]); i++)
    {
        QListWidgetItem* LabelItem = new QListWidgetItem(label_texts[i].c_str());
        QFont font;
        font.setBold(true);
        font.setPixelSize(16);
        LabelItem->setFont(font);
        LabelItem->setForeground(QColor(88,88,88));
        LabelItem->setTextAlignment(Qt::AlignLeft);
        listWidget.addItem(LabelItem);
        for(int j = 0; j < menu_popup_labels_texts[i].size(); j++)
        {
            QListWidgetItem* item = new QListWidgetItem(menu_popup_labels_texts[i][j].second);
            QIcon icon;
            QFont font;
            icon.addPixmap(QPixmap(menu_popup_labels_texts[i][j].first), QIcon::Normal);
            font.setPixelSize(18);
            font.setWeight(50);
            item->setFont(font);
            item->setTextAlignment(Qt::AlignLeft);
            if(j==0 && i == 0)
            {
                item->setFlags(item->flags() & ~Qt::ItemIsEnabled);
                icon.addPixmap(menu_popup_labels_texts[i][j].first,QIcon::Disabled);
            }
            icon.addPixmap(menu_popup_labels_texts[i][j].first,QIcon::Selected);
            item->setIcon(icon);
            listWidget.addItem(item);
            
        }
    }
    QObject::connect(&listWidget, &QListWidget::itemClicked, [&](QListWidgetItem *item) {
        QString text = item->text();
        
    });
    QObject::connect(&listWidget, &QListWidget::itemEntered, [&](QListWidgetItem *item) {
        QString text = item->text();
        if(text=="Kalkulator" || text=="Konwerter")
        {
            listWidget.style()->unpolish(&listWidget);
            listWidget.setObjectName("Label");
            listWidget.style()->polish(&listWidget);
            isLabel = true;
        }
        else if(isLabel)
        {
            listWidget.style()->unpolish(&listWidget);
            listWidget.setObjectName("Default");
            listWidget.style()->polish(&listWidget);
            isLabel = false;
        }
    });
    
    
    listWidget.setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    listWidget.verticalScrollBar()->setSingleStep(12);
    listWidget.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    listWidget.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    listWidget.verticalScrollBar()->setContextMenuPolicy(Qt::NoContextMenu);
    listWidget.setContextMenuPolicy(Qt::CustomContextMenu);
    

    QToolButton* toolbar_menu = new QToolButton();
    toolbar_menu->setFixedSize(60,60);
    toolbar_menu->setObjectName("taskBarMenu");
    toolbar_menu->setIcon(QIcon("src/ikony/main_app/menu_icon.png"));
    toolbar_menu->setStyleSheet("QToolButton::menu-indicator { subcontrol-origin: padding; subcontrol-position: bottom right; image: none; }");

    Shadow_Widget* animationSpecialWidget = new Shadow_Widget(shadowEffect,&mainWindow);
    animationSpecialWidget->setVisible(false);
    SpecialButton* UpMenuButton = new SpecialButton(&mainWindow);
    UpMenuButton->setObjectName("taskBarMenu");
    UpMenuButton->setFixedSize(60,60);
    UpMenuButton->setIcon(QIcon("src/ikony/main_app/menu_icon.png"));
    animationSpecialWidget->setObjectName("animationWidgetTop");

    QWidget* Settings = new QWidget(&mainWindow);
    Settings->setObjectName("animationWidgetBottom");
    Settings->setGraphicsEffect(nextEffect);
    QPushButton* DownMenuButton = new QPushButton(QIcon("src/ikony/main_app/Settings.png"),"   Ustawienia",Settings);
    DownMenuButton->setObjectName("animationWidgetBottom");
    DownMenuButton->setFixedSize(317,70);
    DownMenuButton->show();
    Settings->setVisible(false);

    filter->setAnimationValues(animationSpecialWidget,Settings,&listWidget);
    filter->setValues(Widgets_buttons.back().back(),splitter,UpMenuButton);

    QPropertyAnimation *animation = new QPropertyAnimation(&listWidget, "geometry");
    QPropertyAnimation *animation2 = new QPropertyAnimation(animationSpecialWidget, "geometry");
    QPropertyAnimation *animation3 = new QPropertyAnimation(Settings, "geometry");

    QRect secondStartSize(QRect(0, 0, 0, 60));
    QRect secondEndSize(QRect(0, 0, 317, 60));

    
    QObject::connect(UpMenuButton,&QToolButton::clicked,UpMenuButton,[&](){
        QRect startSize(QPoint(0,60), QSize(0, mainWindow.size().height()-128));
        QRect endSize(QPoint(0,60), QSize(317,mainWindow.size().height()-128));
        if(!listWidget.isVisible())
        {
            UpMenuButton->style()->unpolish(UpMenuButton);
            UpMenuButton->setObjectName("Deactivated");
            UpMenuButton->style()->polish(UpMenuButton);
            QRect thirdStartSize(QRect(0, mainWindow.height()-70, 0, 70));
            QRect thirdEndSize(QRect(0, mainWindow.height()-70, 317, 70));
            //menu->installEventFilter(specialFilter);
            animationSpecialWidget->setVisible(true);
            Settings->setVisible(true);
            listWidget.setVisible(true);
            listWidget.raise();
            Settings->raise();

            animation->setDuration(140);
            animation->setStartValue(startSize);
            animation->setEndValue(endSize);

            animation2->setDuration(140);
            animation2->setStartValue(secondStartSize); // Rozmiar początkowy
            animation2->setEndValue(secondEndSize);

            animation3->setDuration(140);
            animation3->setStartValue(thirdStartSize); // Rozmiar początkowy
            animation3->setEndValue(thirdEndSize);
            
            Settings->setMinimumHeight(1);
            animation->start();
            animation2->start();
            animation3->start();
            emit emitter->customSignal(10);
        }
        else
        {
            
            UpMenuButton->style()->unpolish(UpMenuButton);
            UpMenuButton->setObjectName("taskBarMenu");
            UpMenuButton->style()->polish(UpMenuButton);
            //menu->removeEventFilter(specialFilter);

            
            Settings->setMinimumHeight(0);
            animationSpecialWidget->hide();
            Settings->hide();
            listWidget.setVisible(false);
            emit emitter->customSignal(0);
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
    masterLayout->addLayout(mainLayout);
    mainWindow.show();  // Wyświetlenie głównego okna

    return app.exec();  // Rozpoczęcie głównej pętli aplikacji
}
