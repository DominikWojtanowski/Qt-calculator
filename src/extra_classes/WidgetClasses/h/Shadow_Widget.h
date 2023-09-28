#ifndef SHADOW_WIDGET_H
#define SHADOW_WIDGET_H

#include <QtCore>
#include <QtWidgets>
#include <QtGui>

class Shadow_Widget : public QWidget
{
private:
    QGraphicsDropShadowEffect* m_effect;
protected:
    void hideEvent(QHideEvent *event) override {
       
    }
    void showEvent(QShowEvent *event) override {
        
    }
public:
    Shadow_Widget(QGraphicsDropShadowEffect*);
    Shadow_Widget(QGraphicsDropShadowEffect* ,QWidget*);
};



#endif