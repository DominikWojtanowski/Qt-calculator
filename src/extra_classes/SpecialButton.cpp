#include "SpecialButton.h"

SpecialButton::SpecialButton()
{

}
SpecialButton::SpecialButton(QWidget* parent) : QPushButton{parent}
{

}
void SpecialButton::enterEvent(QEvent* event)
{
    qDebug() << "Wejscie";
}
void SpecialButton::leaveEvent(QEvent* event)
{
    qDebug() << "Wyjscie";
}