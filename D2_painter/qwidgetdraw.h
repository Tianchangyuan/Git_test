#ifndef QWIDGETDRAW_H
#define QWIDGETDRAW_H

#include <QWidget>

class QWidgetDraw : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgetDraw(QWidget *parent = nullptr);
    void draw(QPainter *painter);
    void drawDivide(QPainter *painter,int x,int y,int width,int hight,int wcnt,int hcnt);
    void drawStart(QPainter *painter,int x,int y,int R,int ydegree);

private:
    void paintEvent(QPaintEvent *event);

signals:

public slots:
};

#endif // QWIDGETDRAW_H
