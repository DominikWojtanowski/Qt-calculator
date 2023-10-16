#ifndef EVENT_FILTER_H
#define EVENT_FILTER_H

#include "Signals_Slots/Emitters/h/Emitter.h"
#include "ButtonClasses/h/ButtonWithSlot.h"

#include <iostream>

class EventFilter : public QObject
{
public:
    EventFilter(QObject* = nullptr);
    void setValues(ButtonWithSlot*,QSplitter*,QPushButton*);
    void setAnimationValues(QWidget*, QWidget*, QListWidget*);
protected:
    bool eventFilter(QObject*, QEvent*) override;
private:
    int m_previousWidth;
    QWidget* animationsWidget = nullptr;
    QWidget* animationsWidget2 = nullptr;
    QListWidget* animationList = nullptr;
    QPushButton* m_menu_button = nullptr;
    ButtonWithSlot* m_history = nullptr;
    QSplitter* m_splitter = nullptr;
    Emitter* emitter = new Emitter;
    void hideAll();
};

#endif