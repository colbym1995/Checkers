#include <QMainWindow>
#include "qpainter.h"
#include "qobject.h"


#ifndef PIECE_H
#define PIECE_H


class Piece
{



private:
  bool isBlack;
  bool isKing;

public:

  Piece();
  Piece(bool blk);
  ~Piece();
  void draw(QPainter* paint, int x, int y);
  void SETisBlack(bool input);
  void SETisKing();
  bool GETisBlack();
  bool GETisKing();


};

#endif // PIECE_H
