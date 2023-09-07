#include <iostream>
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
#include <QtGui/QResizeEvent>

class EventFilter : public QObject {
public:
    EventFilter(QObject* parent = nullptr) : QObject{parent}, m_previousWidth{-1} {}
    void setValues(QPushButton* button,QSplitter* splitter){m_history = button;m_splitter=splitter;}
protected:
    bool eventFilter(QObject* obj, QEvent* event) override {
        if (event->type() == QEvent::Resize) {
            QResizeEvent* resizeEvent = static_cast<QResizeEvent*>(event);
            int newWidth = resizeEvent->size().width();
            if(newWidth>=705 && newWidth<=800 && m_splitter->count()==3)
                m_splitter->widget(2)->setFixedWidth(newWidth-390);
                
            if(m_splitter->count()==3)
                m_splitter->widget(2)->setFixedHeight(resizeEvent->size().height());
            if (m_previousWidth == -1) {
                m_previousWidth = newWidth;
            } else {
                int widthDifference = newWidth - m_previousWidth;
                if (widthDifference >= 15 || widthDifference <= -15) {
                    // Wywołaj funkcję, gdy różnica wynosi co najmniej 15 pikseli
                    if((newWidth-widthDifference)<700 && newWidth>=700) {
                        QWidget* newWidget = new QWidget();
                        newWidget->setFixedWidth(310);
                        newWidget->setMaximumWidth(410);
                        newWidget->setStyleSheet("border-left:1px solid black;");
                        m_splitter->addWidget(newWidget);

                        m_history->hide();
                    }
                    else if(!m_history->isVisible() && newWidth<700)
                    {
                        m_history->show();
                        m_splitter->widget(2)->deleteLater();
                    }
                        
                    m_previousWidth = newWidth;
                    
                }
            }
            
        }

        // Pozostałe obsługiwane zdarzenia
        return false;
    }

private:
    int m_previousWidth;
    QPushButton* m_history = nullptr;
    QSplitter* m_splitter = nullptr;
};


int main(int argc, char *argv[])
{
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
    std::vector<QWidget*>Widgets;
    std::vector<std::vector<QPushButton*>>Widgets_buttons;
    std::string image_paths[]{"ikony/menu_icon.png","ikony/leave_on_top.png","ikony/history.png"};
    
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
        
    Widgets_buttons.push_back({new QPushButton(""),new QPushButton("")});
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
    QObject::connect(Widgets_buttons[0][0],&QPushButton::clicked,[&](){
        QMessageBox::information(&mainWindow,"Kliknieto menu","Kilknieto menu");
    });


    QLabel *label = new QLabel("Standardowy");
    label->setFixedSize(170,60);
    label->setMargin(10);
    label->setStyleSheet("font-size:21px;font-weight:500;");
    
    for(int i = 0; i < Widgets_buttons[0].size();i++)
    {
        if(i==1)
            sub_layouts[0]->addWidget(label);
        sub_layouts[0]->addWidget(Widgets_buttons[0][i]);
    }
    sub_layouts[1]->addWidget(Widgets_buttons.back().back()); // Nalepsza linijka mojego kodu xD
        
    mainLayout->addWidget(splitter);

    mainWindow.show();  // Wyświetlenie głównego okna

    app.setWindowIcon(QIcon("ikony/kalkulatoricon.png"));

    
    return app.exec();  // Rozpoczęcie głównej pętli aplikacji
}
