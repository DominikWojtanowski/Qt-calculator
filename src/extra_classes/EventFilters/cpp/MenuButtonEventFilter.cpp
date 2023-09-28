#include "EventFilters/h/MenuButtonEventFilter.h"

MenuButtonEventFilter::MenuButtonEventFilter(bool& Value,QObject* parent, QMenu* menu) : QObject{parent}, m_menu{menu}, m_previousWidth{-1}, m_showValue{Value} 
{}
void MenuButtonEventFilter::setButtonStyle(QPushButton* buttonToSet,int option,const QString& OneName = "Activated", const QString& SecondName = "Deactivated")
{
    buttonToSet->style()->unpolish(buttonToSet);
    option == 1 ? buttonToSet->setObjectName(OneName) : buttonToSet->setObjectName(SecondName);
    buttonToSet->style()->polish(buttonToSet);
}
void MenuButtonEventFilter::setWidgets(QWidget* TopWidget, QWidget* DownWidget)
{
    widgets[0] = TopWidget;
    widgets[1] = DownWidget;
    
}
bool MenuButtonEventFilter::eventFilter(QObject* obj, QEvent* event)
{   
    if(event->type() == QEvent::Hide)
    {
        wasChangedTop = false;
        widgets[0]->hide();
        widgets[1]->hide();
        m_menuButton_top->style()->unpolish(m_menuButton_top);
        m_menuButton_top->setObjectName("taskBarMenu");
        m_menuButton_top->style()->polish(m_menuButton_top);
    }
    if(event->type() == QEvent::MouseMove || event->type() == QEvent::Resize)
    {
        QMouseEvent* Event = reinterpret_cast<QMouseEvent*>(event);
        QPoint pos = Event->pos();
        int x = pos.x();
        int y = pos.y();
        if(((x>=3 && x<=55 && y<=-3 && y>=-55) || (x == 0 && y == 0)))
        {
            if(wasChangedTop == false)
            {
                wasChangedTop = true;
                setButtonStyle(m_menuButton_top,1);
            }
        }
        else if((y>=483 && y<=522) && (x>=0 && x<=312))
        {
            if(wasChangedBottom == false)
            {
                wasChangedBottom = true;
                setButtonStyle(m_menuButton_bottom,1,"ActiveAnimationWidgetBottom","DeactiveAnimationWidgetBottom");
            }
        }
        else
        {
            if(wasChangedTop)
            {
                setButtonStyle(m_menuButton_top,0);
                wasChangedTop = false;
            }
            if(wasChangedBottom)
            {
                setButtonStyle(m_menuButton_bottom,0,"ActiveAnimationWidgetBottom","DeactiveAnimationWidgetBottom");
                wasChangedBottom = false;
            }
        }       
    }
    else if (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick ||  
    event->type() == QEvent::MouseButtonRelease ) {
        // Obsługuje kliknięcie myszą
            QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
            if(mouseEvent->pos().x() > 317)
                m_showValue = true;
            if(mouseEvent->pos().x() > 317 || (((mouseEvent->pos().x()>=3 && mouseEvent->pos().x()<=55 && 
            mouseEvent->pos().y()<=-3 && mouseEvent->pos().y()>=-55) || (mouseEvent->pos().x() == 0 && mouseEvent->pos().y() == 0))))
            {
                wasChangedTop = false;
                if(m_menuButton_top->isVisible())
                {
                    widgets[0]->hide();
                    widgets[1]->hide();
                }
                return false;
            }    
            return true;
    }
    return false;
}

void MenuButtonEventFilter::setValues(QPushButton* TopButton, QPushButton* BottomButton)
{
    m_menuButton_top = TopButton;
    m_menuButton_bottom = BottomButton;
}

void MenuButtonEventFilter::deleteAll()
{
    m_menuButton_top = nullptr;
    m_menuButton_bottom = nullptr;
}