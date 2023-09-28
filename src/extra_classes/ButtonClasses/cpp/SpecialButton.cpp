#include "ButtonClasses/h/SpecialButton.h"

SpecialButton::SpecialButton()
{

}
SpecialButton::SpecialButton(QWidget* parent) : QPushButton{parent}
{

}
void SpecialButton::enterEvent(QEvent* event)
{}
void SpecialButton::leaveEvent(QEvent* event)
{}