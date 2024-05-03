#include "square.h"
#include "king.h"
#include "knight.h"
#include "rook.h"


Square::~Square(){
}

Square::Square(Color color, Position coordo)

{
    color_ = color;
    position_ = coordo;
}

Position Square::getPosition() const
{
    return position_;
}

void Square::setPieceSquare(PiecesAbs* piece)
{
    this->piece_ = piece;
    isOccupied_ = true;
    piece->setPosition(this->getPosition());
};

void Square::setPieceSquare(PieceType piece, Color color){
    if(piece == PieceType::King){
        King* king = new King(color,position_);
        piece_ = king;
        isOccupied_ = true;
    }
    else if(piece == PieceType::Knight){
        Knight* knight = new Knight(color,position_);
        piece_ = knight;
        isOccupied_ = true;
    }
    else if(piece == PieceType::Rook){
        Rook* rook = new Rook(color,position_);
        piece_ = rook;
        isOccupied_ = true;
    }
}
PiecesAbs* Square::getPieceSquare()
{
    return piece_;
};

void Square::setUnoccupiedSquare()
{
    this->piece_ = nullptr;
    isOccupied_ = false;
}
