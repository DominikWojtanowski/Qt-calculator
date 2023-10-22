#include "WidgetClasses/h/MainWindow.h"


MainWindow::MainWindow(QWidget* parent) : QWidget{parent}, m_previousWidth{-1}
{}
void MainWindow::hideSlot(int value)
{
    qDebug() << "test";
    QMouseEvent *mouseEvent = new QMouseEvent(QEvent::MouseButtonPress, QPoint(328,0), Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
    this->eventFilter(nullptr,mouseEvent);
}
bool MainWindow::eventFilter(QObject* obj, QEvent* event)
{
    //qDebug() << event->type();
    if(event->type() == QEvent::WindowStateChange)
    {
        QResizeEvent* resizeEvent = static_cast<QResizeEvent*>(event);
        if(m_splitter->count()==3)
            m_splitter->widget(2)->setFixedHeight(resizeEvent->size().height());
    }
    if(event->type() == QEvent::WindowStateChange)
        hideAll();
    if(event->type() == QEvent::MouseButtonDblClick || event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
        if(mouseEvent->pos().x() > 317)
            hideAll();
    }
    if (event->type() == QEvent::Resize) {
        hideAll();
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


void MainWindow::hideAll()
{
    if(animationList->isVisible())
    {
        QObject::connect(emitter, SIGNAL(customSignal(int)), m_history, SLOT(customSlot(int)));
        emit emitter->customSignal(0);
        m_menu_button->style()->unpolish(m_menu_button);
        m_menu_button->setObjectName("taskBarMenu");
        m_menu_button->style()->polish(m_menu_button);
        animationList->hide();
        animationsWidget2->hide();
        animationsWidget->hide();
    }
}
void MainWindow::setAnimationValues(QWidget* upAnimationWidget,QWidget* downAnimationWidget,QListWidget* listAnimation)
{
    animationsWidget = upAnimationWidget;
    animationsWidget2 = downAnimationWidget;
    animationList = listAnimation;
}
void MainWindow::setValues(ButtonWithSlot* button, QSplitter* splitter,QPushButton* menuButton)
{
    m_history = button;
    m_splitter = splitter;
    m_menu_button = menuButton;
}