#ifndef BUTTON_WITH_SLOT_H
#define BUTTON_WITH_SLOT_H

#include <QtCore>
#include <QtWidgets>
#include <QtGui>

class ButtonWithSlot : public QPushButton
{
    Q_OBJECT
    using QPushButton::QPushButton;
private:
    bool isDisabled{false};
    
public slots:
    void customSlot(int);
};


#endif //BUTTON_WITH_SLOT_H