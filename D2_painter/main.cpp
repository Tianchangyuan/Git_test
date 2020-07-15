#include <QApplication>
#include <QWidget>
#include <QPainter>
#include "qwidgetdraw.h"
//#include "qlableclock.h"
#include <QLabel>
#include <QDebug>
#include <QPushButton>
#include <QMouseEvent>
#include <QDateTime>
#include <QTimer>
#include "qlabelclock.h"
int main(int argc, char * argv[])
{
    QApplication a(argc, argv);

    QWidgetDraw drawWin;
    QLabelClock *labelClock =new QLabelClock(&drawWin);
    labelClock->setGeometry(300,500,300,30);
    labelClock->setStyleSheet("color:black");//配置样式表
    drawWin.show();

    return a.exec();
}
