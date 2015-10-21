#include "piece.h"
#include "qpainter.h"







    Piece::Piece()
    {
        isBlack = false;
        isKing = false;
    }

    Piece::Piece(bool blk)
    {
        if(blk == false)
            isBlack = false;
        else
            isBlack = true;
        isKing = false;
    }

    Piece::~Piece()
    {

    }

    void Piece::draw(QPainter* paint, int x, int y)
    {

        if(isBlack == true)
        {
            paint->setBrush(Qt::white);
            paint->drawEllipse(((80*(x))+2),((80*(y))+1),74,74);
            paint->setBrush(Qt::black);
            paint->drawEllipse(((80*(x))+4),((80*(y))+3),70,70);
        }
        else
        {
            paint->setBrush(Qt::black);
            paint->drawEllipse(((80*(x))+2),((80*(y))+1),74,74);
            paint->setBrush(Qt::white);
            paint->drawEllipse(((80*(x))+4),((80*(y))+3),70,70);
        }


    }

    void Piece::SETisBlack(bool input)
    {
        isBlack = input;
    }

    void Piece::SETisKing()
    {
        isKing = true;
    }

    bool Piece::GETisBlack()
    {
        return isBlack;
    }

    bool Piece::GETisKing()
    {
        return isKing;
    }



