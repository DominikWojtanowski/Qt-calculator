#include "MenuButtonEventFilter.h"

MenuButtonEventFilter::MenuButtonEventFilter(QObject* parent) : QObject{parent}, m_previousWidth{-1} 
{}

bool MenuButtonEventFilter::eventFilter(QObject* obj, QEvent* event)
{
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