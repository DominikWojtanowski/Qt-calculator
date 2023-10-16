#include "ButtonClasses/h/ButtonWithSlot.h"

void ButtonWithSlot::customSlot(int value)
{
    value == 10 ? setEnabled(false) : setEnabled(true);
}