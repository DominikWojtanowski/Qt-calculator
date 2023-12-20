#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "Signals_Slots/Emitters/h/Emitter.h"
#include "ButtonClasses/h/ButtonWithSlot.h"

class MainWindow : public QWidget
{
    Q_OBJECT
    

public slots:
    void hideSlot(int,int);
public:
    MainWindow(QWidget* = nullptr);
    void setValues(ButtonWithSlot*,QPushButton*);
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
    Emitter* emitter = new Emitter;
    void hideAll(QMouseEvent*);
};


#endif // MAIN_WINDOW_H