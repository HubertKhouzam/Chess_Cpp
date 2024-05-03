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
        King king = King(color,position_);
        this->piece_ = &king;
        isOccupied_ = true;
    }
    else if(piece == PieceType::Knight){
        Knight knight = Knight(color,position_);
        this->piece_ = &knight;
        isOccupied_ = true;
    }
    else if(piece == PieceType::Rook){
        Rook rook = Rook(color,position_);
        this->piece_ = &rook;
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
