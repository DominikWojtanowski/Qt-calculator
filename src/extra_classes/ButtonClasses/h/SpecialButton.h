#ifndef SPECIAL_BUTTON_H
#define SPECIAL_BUTTON_H

#include <QtCore>
#include <QtWidgets>
#include <QtGui>

class SpecialButton : public QPushButton
{
    Q_OBJECT
protected:
    void enterEvent(QEvent*) override;
    void leaveEvent(QEvent*) override;
public:
    SpecialButton();
    SpecialButton(QWidget*);
};

#endif // SPECIAL_BUTTON_H