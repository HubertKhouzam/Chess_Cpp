#pragma once
#include "pieces.h"
#include "Color.h"
#include "position.h"
#include "TypePiece.h"

using namespace piece;


class Square
{
public :
    Square(Color color, Position coordo);
    Square() {};
    virtual ~Square();
    Position getPosition() const;
    void setPieceSquare(PiecesAbs* piece);
    void setPieceSquare(PieceType piece, Color color);
    piece::PiecesAbs* getPieceSquare();
    void setUnoccupiedSquare();
    Color getColor() ;
    PiecesAbs* piece_ = nullptr;

private :
    Position position_;
    bool isOccupied_ = false;
    Color color_;
};


