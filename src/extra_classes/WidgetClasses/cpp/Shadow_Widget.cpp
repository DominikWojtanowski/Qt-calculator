#include "WidgetClasses/h/Shadow_Widget.h"

Shadow_Widget::Shadow_Widget(QGraphicsDropShadowEffect* effect,bool& show) : QWidget{}, m_show{show}
{
    m_effect = effect;
    this->setGraphicsEffect(m_effect);
}
Shadow_Widget::Shadow_Widget(QGraphicsDropShadowEffect* effect, QWidget* parent,bool& show) : QWidget{parent}, m_show{show}
{
    m_effect = effect;
    this->setGraphicsEffect(m_effect);
}

