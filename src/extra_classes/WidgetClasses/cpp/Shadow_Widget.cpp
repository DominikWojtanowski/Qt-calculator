#include "WidgetClasses/h/Shadow_Widget.h"

Shadow_Widget::Shadow_Widget(QGraphicsDropShadowEffect* effect) : QWidget{}
{
    m_effect = effect;
    this->setGraphicsEffect(m_effect);
}
Shadow_Widget::Shadow_Widget(QGraphicsDropShadowEffect* effect, QWidget* parent) : QWidget{parent}
{
    m_effect = effect;
    this->setGraphicsEffect(m_effect);
}

