#include "qwidgetdraw.h"
#include <QPaintEvent>
#include <QPainter>
#include <Qtmath>

//#include "qlableclock.h"
#include <QDateTime>
#include <QTimer>
#include <QMouseEvent>


QWidgetDraw::QWidgetDraw(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("12组田昌元");
    // 1.2880x1920; 2. 2400x1600; 3. 1920x1280; 4. 1440x960; 5. 960x640; 6. 660x440
    this->resize(660+100, 440+100);
    // 必须完成todo屏幕上显示团队信息，个人名字/学号
    // 必须完成todo界面上显示时间
    // 拓展：时间显示用LCDnumber替代QLabel
}

void QWidgetDraw::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter();
    // 启动绘图
    painter->begin(this);
    this->draw(painter);
    // 绘图结束
    painter->end();
}

void QWidgetDraw::draw(QPainter *painter)
{
    int step;
    // 配置画笔参数
    painter->setPen(QPen(Qt::black, Qt::DashLine));
    painter->setBrush(QBrush(Qt::red, Qt::SolidPattern));
    // 画国旗外框
    painter->drawRect(50, 50, 660, 440);
    // 水平垂直2等分
    this->drawDivide(painter, 50, 50, 660, 440, 2, 2);
    // 左上角10x15等分
    this->drawDivide(painter, 50, 50, 660/2, 440/2, 15, 10);
    // 绘制大圆
    step = 330/15;
    painter->drawEllipse(50 + step*2, 50 + step*2, step*6, step*6);
    painter->drawEllipse(50 + step*9, 50 + step*1, step*2, step*2);
    // todo
    // 必须完成其他4个小圆
    // 拓展：画大的五角星
    //画圆圈
    step=330/15;
    painter->drawEllipse(50+step*2,50+step*2,step*6,step*6);
    painter->drawEllipse(50+step*9,50+step*1,step*2,step*2);

    painter->drawEllipse(50+step*11,50+step*3,step*2,step*2);
    painter->drawEllipse(50+step*11,50+step*6,step*2,step*2);
    painter->drawEllipse(50+step*9,50+step*8,step*2,step*2);

    painter->setPen(QPen(Qt::yellow,Qt::DashLine));
    this->drawStart(painter,50+step*5,50+step*5,3*step,0);
    this->drawStart(painter,50+step*10,50+step*2,1*step,23);
    this->drawStart(painter,50+step*12,50+step*4,1*step,46);
    this->drawStart(painter,50+step*12,50+step*7,1*step,70);
    this->drawStart(painter,50+step*10,50+step*9,1*step,18);
}

void QWidgetDraw::drawDivide(QPainter *painter, int startX, int startY, int width, int hight, int wCnt, int hCnt){
    int step = width/wCnt;
    int cnt = 0;

    // 水平方向等分
    for(cnt = 0; cnt < wCnt; cnt++)
        painter->drawLine(startX+step*cnt, startY, startX+step*cnt, startY+hight);

    // 垂直方向等分
    step = hight/hCnt;
    for(cnt = 0; cnt < hCnt; cnt++)
        painter->drawLine(startX, startY+step*cnt, startX+width, startY+step*cnt);
}
void QWidgetDraw::drawStart(QPainter *painter,int x,int y,int R,int ydegree){
    int ponintx[5],poninty[5];
    double rad=3.1415926/180;
    double r=R*sin(18 * rad) / cos(36 * rad);
    for (int k = 0; k < 5; k++){
        ponintx[k] = int(x - (R * cos((90 + k * 72 + ydegree) *rad)));
        poninty[k] = int(y - (R * sin((90 + k * 72 + ydegree) *rad)));
    }
    painter->drawLine(ponintx[0],poninty[0],ponintx[2],poninty[2]);
    painter->drawLine(ponintx[0],poninty[0],ponintx[3],poninty[3]);

    painter->drawLine(ponintx[1],poninty[1],ponintx[4],poninty[4]);
    painter->drawLine(ponintx[2],poninty[2],ponintx[4],poninty[4]);
    painter->drawLine(ponintx[1],poninty[1],ponintx[3],poninty[3]);
}
