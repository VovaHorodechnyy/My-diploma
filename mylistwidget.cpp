#include "mylistwidget.h"

#include "mylistwidget.h"

#include <QMouseEvent>

MyListWidget::MyListWidget(QWidget *parent) :
    QListWidget(parent)
{

}

MyListWidget::~MyListWidget()
{

}

void MyListWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton){
        QPoint  pos = (event->pos());
        emit rightClick(&pos);
    } else {
        QListWidget::mousePressEvent(event);
    }
}
