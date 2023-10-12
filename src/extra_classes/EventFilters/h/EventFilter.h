#ifndef EVENT_FILTER_H
#define EVENT_FILTER_H

#include <QtCore>
#include <QtWidgets>
#include <QtGui>
#include <iostream>

class EventFilter : public QObject
{
public:
    EventFilter(QObject* = nullptr);
    void setValues(QPushButton*,QSplitter*,QPushButton*);
    void setAnimationValues(QWidget*, QWidget*, QListWidget*);
protected:
    bool eventFilter(QObject*, QEvent*) override;
private:
    int m_previousWidth;
    QWidget* animationsWidget = nullptr;
    QWidget* animationsWidget2 = nullptr;
    QListWidget* animationList = nullptr;
    QPushButton* m_menu_button = nullptr;
    QPushButton* m_history = nullptr;
    QSplitter* m_splitter = nullptr;
    void hideAll();
};

#endif