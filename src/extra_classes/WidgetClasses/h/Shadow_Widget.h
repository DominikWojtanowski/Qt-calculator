#ifndef SHADOW_WIDGET_H
#define SHADOW_WIDGET_H

#include <QtCore>
#include <QtWidgets>
#include <QtGui>

class Shadow_Widget : public QWidget
{
private:
    QGraphicsDropShadowEffect* m_effect;
public:
    Shadow_Widget(QGraphicsDropShadowEffect* );
    Shadow_Widget(QGraphicsDropShadowEffect* ,QWidget* );
};



#endif