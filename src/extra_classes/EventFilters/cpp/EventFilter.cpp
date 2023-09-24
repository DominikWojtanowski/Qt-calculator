#include "EventFilters/h/EventFilter.h"

EventFilter::EventFilter(QObject* parent) : QObject{parent}, m_previousWidth{-1} 
{}

bool EventFilter::eventFilter(QObject* obj, QEvent* event)
{
    if(event->type() == QEvent::WindowStateChange)
    {
        QResizeEvent* resizeEvent = static_cast<QResizeEvent*>(event);
        if(m_splitter->count()==3)
            m_splitter->widget(2)->setFixedHeight(resizeEvent->size().height());
    }
    if (event->type() == QEvent::Resize) {
        QResizeEvent* resizeEvent = static_cast<QResizeEvent*>(event);
        int newWidth = resizeEvent->size().width();
        if(newWidth>=705 && newWidth<=800 && m_splitter->count()==3)
            m_splitter->widget(2)->setFixedWidth(newWidth-390);
                
        if(m_splitter->count()==3)
             m_splitter->widget(2)->setFixedHeight(resizeEvent->size().height());
        if (m_previousWidth == -1) {
            m_previousWidth = newWidth;
        } else {
            int widthDifference = newWidth - m_previousWidth;
            if (widthDifference >= 15 || widthDifference <= -15) {
                // Wywołaj funkcję, gdy różnica wynosi co najmniej 15 pikseli
                if((newWidth-widthDifference)<700 && newWidth>=700) {
                    QWidget* newWidget = new QWidget();
                    newWidget->setFixedWidth(310);
                    newWidget->setMaximumWidth(410);
                    newWidget->setStyleSheet("border-left:1px solid black;");
                    m_splitter->addWidget(newWidget);
                    m_history->hide();
                }
                else if(!m_history->isVisible() && newWidth<700)
                {
                    m_history->show();
                    m_splitter->widget(2)->deleteLater();
                }
                m_previousWidth = newWidth;     
            }
        }       
    }
    return false;
}




void EventFilter::setValues(QPushButton* button, QSplitter* splitter)
{
    m_history = button;
    m_splitter=splitter;
}