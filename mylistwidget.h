#ifndef MYLISTWIDGET_H
#define MYLISTWIDGET_H

#include <QListWidget>
#include <QListWidgetItem>
#include <QPoint>
#include <QMenu>

class MyListWidget : public QListWidget
{
   Q_OBJECT
public:
   MyListWidget(QWidget *parent = 0);
   ~MyListWidget();
private:
   void mousePressEvent(QMouseEvent *event);
signals:
   void rightClick(QPoint* pos);
};

#endif // MYLISTWIDGET_H
