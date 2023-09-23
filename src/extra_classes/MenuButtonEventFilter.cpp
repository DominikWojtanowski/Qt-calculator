#include "MenuButtonEventFilter.h"

MenuButtonEventFilter::MenuButtonEventFilter(QObject* parent, QMenu* menu) : QObject{parent}, m_menu{menu}, m_previousWidth{-1} 
{}

bool MenuButtonEventFilter::eventFilter(QObject* obj, QEvent* event)
{
    std::cout << event->type() << std::endl;
    
    if(event->type() == QEvent::MouseMove || event->type() == QEvent::Resize)
    {
        QMouseEvent* Event = reinterpret_cast<QMouseEvent*>(event);
        QPoint pos = Event->pos();
        int x = pos.x();
        int y = pos.y();
        if(((x>=3 && x<=55 && y<=-3 && y>=-55) || (x == 0 && y == 0)))
        {
            if(wasChanged == false)
            {
                wasChanged = true;
                m_history->setStyleSheet("QPushButton{background-color:#d7d7d7;border-radius:10px;}");
            }
        }
        else
        {
            m_history->setStyleSheet("QPushButton:hover{background-color:#d7d7d7;border-radius:10px;} QPushButton{background-color:rgb(231,231,231);border:none;text-align: center;margin: 4px;}");
            wasChanged = false;
        }       
    }
    else if (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick ||  
    event->type() == QEvent::MouseButtonRelease ) {
        // Obsługuje kliknięcie myszą
            QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
            if(mouseEvent->pos().x() > 317 )
                return false;
            return true;
    }
    return false;
}

void MenuButtonEventFilter::setValues(QPushButton* button)
{
    m_history = button;
}

void MenuButtonEventFilter::deleteAll()
{
    m_history = nullptr;
}