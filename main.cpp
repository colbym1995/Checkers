#include "checkers.h"
#include "piece.h"

#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Checkers w;
    w.show();

    return a.exec();
}
