#include "piece.h"
#include "qpainter.h"







    Piece::Piece()
    {
        isBlack = false;
        isKing = false;
    }

    Piece::Piece(bool blk)
    {
        isBlack = blk;
        isKing = false;
    }

    Piece::~Piece()
    {

    }

    void Piece::draw(QPainter* paint, int x, int y)
    {

        if(isBlack == true)
        {
            paint->setBrush(QColor(255, 137, 0, 255));
            paint->drawEllipse(((80*(x))+2),((80*(y))+1),74,74);
            paint->setBrush(Qt::black);
            paint->drawEllipse(((80*(x))+4),((80*(y))+3),70,70);
            if(isKing == true)
            {
                paint->setBrush(QColor(255,215,0));
                paint->drawEllipse(((80*(x))+13),((80*(y))+13),50,50);
            }
        }
        else
        {
            paint->setBrush(Qt::black);
            paint->drawEllipse(((80*(x))+2),((80*(y))+1),74,74);
            paint->setBrush(QColor(255, 137, 0, 255));
            paint->drawEllipse(((80*(x))+4),((80*(y))+3),70,70);
            if(isKing == true)
            {
                paint->setBrush(QColor(255,215,0));
                paint->drawEllipse(((80*(x))+13),((80*(y))+13),50,50);
            }
        }


    }

    void Piece::SetWhite()
    {
        isBlack = false;
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



