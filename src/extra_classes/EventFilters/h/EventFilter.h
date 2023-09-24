#ifndef EVENT_FILTER_H
#define EVENT_FILTER_H

#include <QtCore/qobject.h>
#include <QtCore/QEvent>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qsplitter.h>
#include <QtGui/QResizeEvent>
#include <iostream>

class EventFilter : public QObject
{
public:
    EventFilter(QObject* = nullptr);
    void setValues(QPushButton*,QSplitter*);
protected:
    bool eventFilter(QObject*, QEvent*) override;
private:
    int m_previousWidth;
    QPushButton* m_history = nullptr;
    QSplitter* m_splitter = nullptr;
};

#endif