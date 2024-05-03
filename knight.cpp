#include "knight.h"

Knight::Knight(Color color, Position coordo) : PiecesAbs(color, coordo) {}

Knight::~Knight(){}


PieceType Knight::getPieceType() const {
    return nomPiece;
}


bool Knight::acceptedMovement(Position coordo)
{
    if((0 <= coordo.x && coordo.x< 8) && (0<= coordo.y && coordo.y < 8))
    {
        if( ((coordo.y == getPiecePosition().y + 2) && (coordo.x == getPiecePosition().x + 1))  ||
            ((coordo.y == getPiecePosition().y + 2) && (coordo.x == getPiecePosition().x - 1))  ||
            ((coordo.y == getPiecePosition().y + 1) && (coordo.x == getPiecePosition().x + 2))  ||
            ((coordo.y == getPiecePosition().y + 1) && (coordo.x == getPiecePosition().x - 2))  ||
            ((coordo.y == getPiecePosition().y - 1) && (coordo.x == getPiecePosition().x + 2))  ||
            ((coordo.y == getPiecePosition().y - 1) && (coordo.x == getPiecePosition().x - 2))  ||
            ((coordo.y == getPiecePosition().y - 2) && (coordo.x == getPiecePosition().x + 1))  ||
            ((coordo.y == getPiecePosition().y - 2) && (coordo.x == getPiecePosition().x - 1))
            )
        {
            return true;
        }

        else{
            return false;
        }

    }

    else{
        return false;
    }
}
