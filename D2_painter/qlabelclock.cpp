#include "qlabelclock.h"
#include <QDateTime>
#include <QTimer>
QLabelClock::QLabelClock(QWidget *parent):QLabel(parent){

        this->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss dddd"));
        this->setGeometry(0,150-30,300,30);
        this->setStyleSheet("color:white");
        timer =new QTimer(parent);
        connect(timer,&QTimer::timeout,this,&QLabelClock::refresh);
        timer->start(1000);
}
void QLabelClock::refresh(){
    if (refreshEnable==true)
       this->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss dddd"));

}
void QLabelClock::mousePressEvent(QMouseEvent *ev){
       if(ev->button()==Qt::LeftButton)
          refreshEnable=!refreshEnable;
}
