#include "ButtonClasses/h/ButtonWithSlot.h"

void ButtonWithSlot::customSlot(int value)
{
    value == 10 ? setEnabled(false) : setEnabled(true);
}
void ButtonWithSlot::mousePressEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
    QPushButton::mousePressEvent(event);
    setMouseTracking(true);
}