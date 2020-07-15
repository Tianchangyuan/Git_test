#ifndef QLABELCLOCK_H
#define QLABELCLOCK_H
#include <QWidget>
#include <QLabel>
#include "QMouseEvent"
class QLabelClock : public QLabel
{
    Q_OBJECT
public:
  QTimer *timer;
  int refreshEnable=1;
  QLabelClock(QWidget *parent);
  void refresh();
  void mousePressEvent(QMouseEvent *ev);
};

#endif // QLABELCLOCK_H
