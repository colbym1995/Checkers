#ifndef CHECKERS_H
#define CHECKERS_H

#include <QMainWindow>
#include "qpainter.h"
#include "piece.h"


class Checkers : public QMainWindow
{
    Q_OBJECT

public:
    int blackCount;
    int whiteCount;
    bool newGame;

    unsigned startx;
    unsigned starty;
    unsigned endx;
    unsigned endy;

    Checkers(QWidget *parent = 0);
    ~Checkers();
    void paintEvent(QPaintEvent* e);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

};

#endif // CHECKERS_H
