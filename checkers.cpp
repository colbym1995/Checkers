#include "checkers.h"
#include "qpainter.h"
#include "piece.h"
#include <QMouseEvent>
#include "qdebug.h"




bool newGame = true;
Piece* pieces[8][8] = {{NULL}};
Piece b1 = new Piece();
Piece b2 = new Piece();
Piece b3 = new Piece();
Piece b4 = new Piece();
Piece b5 = new Piece();
Piece b6 = new Piece();
Piece b7 = new Piece();
Piece b8 = new Piece();
Piece b9 = new Piece();
Piece b10= new Piece();
Piece b11= new Piece();
Piece b12= new Piece();
Piece w1 = new Piece();
Piece w2 = new Piece();
Piece w3 = new Piece();
Piece w4 = new Piece();
Piece w5 = new Piece();
Piece w6 = new Piece();
Piece w7 = new Piece();
Piece w8 = new Piece();
Piece w9 = new Piece();
Piece w10 = new Piece();
Piece w11 = new Piece();
Piece w12 = new Piece();


    unsigned startx;
    unsigned starty;



unsigned endx;
unsigned endy;


Checkers::Checkers(QWidget *parent)
    : QMainWindow(parent)
{
    resize(80*8,80*8);
    //initializePieces();
    repaint();
}

Checkers::~Checkers()
{

}

void Checkers::paintEvent(QPaintEvent* e)
{
    if(newGame==true)
    {
        w1.SetWhite();
        w2.SetWhite();
        w3.SetWhite();
        w4.SetWhite();
        w5.SetWhite();
        w6.SetWhite();
        w7.SetWhite();
        w8.SetWhite();
        w9.SetWhite();
        w10.SetWhite();
        w11.SetWhite();
        w12.SetWhite();

        pieces[0][0] = &b1;
        pieces[0][2] = &b2;
        pieces[0][4] = &b3;
        pieces[0][6] = &b4;
        pieces[1][1] = &b5;
        pieces[1][3] = &b6;
        pieces[1][5] = &b7;
        pieces[1][7] = &b8;
        pieces[2][0] = &b9;
        pieces[2][2] = &b10;
        pieces[2][4] = &b11;
        pieces[2][6] = &b12;
        pieces[5][1] = &w1;
        pieces[5][3] = &w2;
        pieces[5][5] = &w3;
        pieces[5][7] = &w4;
        pieces[6][0] = &w5;
        pieces[6][2] = &w6;
        pieces[6][4] = &w7;
        pieces[6][6] = &w8;
        pieces[7][1] = &w9;
        pieces[7][3] = &w10;
        pieces[7][5] = &w11;
        pieces[7][7] = &w12;

        newGame = false;
    }

    QPainter paint(this);
    for(int y = 0; y < 8; y++)
    {


      for(int x = y%2; x<8; x=x+2 )
      {

          paint.fillRect(QRect(80*x,80*y,80,80), QColor(75,0,130));

      }

    }
    for(int y = 0; y < 8; y++)
    {
      for(int x = (y%2)-1; x<8; x=x+2 )
      {
          paint.fillRect(QRect(80*(x),80*(y),80,80), QColor(204,0,0));

      }

    }
    for(int i = 0; i < 8; i++)
        {
            for(int j =0; j <8; j++)
            {
                if(pieces[i][j] != NULL)
                {
                    pieces[i][j]->draw(&paint, j, i);
                   // qDebug() << "pieceDrwn";
                }
            }
        }


    }

void Checkers::mousePressEvent(QMouseEvent* evnt)
{


 starty = evnt->x()/80;
 startx = evnt->y()/80;
 qDebug()<< startx << " " << starty;
}

void Checkers::mouseReleaseEvent(QMouseEvent* evnt)
{
    endy = evnt->x()/80;
    endx = evnt->y()/80;
    qDebug()<< endx << " " << endy;
    qDebug() << pieces[startx][starty];
    if(pieces[startx][starty] != NULL && pieces[endx][endy] == NULL
       && startx != endx && starty != endy)
    {
        qDebug()<<"honk";
        if(pieces[startx][starty]->GETisBlack() == false)
        {
            qDebug()<<"SCREE";
            if(pieces[startx][starty]->GETisKing() ==false)
            {
                qDebug()<<"...";
                if(endx < startx &&  (startx - endx <=2 || startx - endx >= -2)&& (starty - endy <=2 || starty - endy >= -2))
                {
                    if((startx - endx ==1 || startx - endx == -1)&& (starty - endy ==1 || starty - endy == -1))
                    {
                        qDebug()<<"moved orange not k";
                        pieces[endx][endy]= pieces[startx][starty];
                        pieces[startx][starty] = NULL;
                      }
                      else if((startx - endx ==2 || startx - endx == -2)&& (starty - endy ==2 || starty - endy == -2))
                      {

                        if((startx - endx == 2 || endx - startx == 2) && pieces[(startx +endx)/2][(starty +endy)/2] != NULL)
                        {
                            if(pieces[(startx +endx)/2][(starty +endy)/2]->GETisBlack() != false)
                            {
                                qDebug() << "kill" << (startx +endx)/2 << " " << (startx +endx)/2;
                                pieces[(startx +endx)/2][(starty +endy)/2] = NULL;
                                qDebug()<<"moved orange not k";
                                pieces[endx][endy]= pieces[startx][starty];
                                pieces[startx][starty] = NULL;
                            }
                         }
                      }
                }
            }
            else
            {
                qDebug()<<"moved orange king";
                pieces[endx][endy]= pieces[startx][starty];
                pieces[startx][starty] = NULL;
                if(starty % endy == 0)
                {
                    qDebug() << "kill" << (startx +endx)/2 << " " << (startx +endx)/2;
                    pieces[(startx +endx)/2][(starty +endy)/2] = NULL;
                }
            }
        }


    }
    repaint();
}

