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


    Checkers(QWidget *parent = 0);
    ~Checkers();
    void paintEvent(QPaintEvent* e);
};

#endif // CHECKERS_H
