#include "board.h"  //no need?
#include <iostream>  //no need?
#include "rook.h"

Rook::Rook(Color color, Position coordo) : PiecesAbs(color, coordo) {
}

Rook::~Rook(){
}

const std::string Rook::getPiece() {
    return "Rook";
}

bool Rook::acceptedMovement(Position coordo)
{
    if ((0 <= coordo.x && coordo.x< 8) && (0<= coordo.y && coordo.y < 8))
    {
        if (coordo.x != getPiecePosition().x && coordo.y != getPiecePosition().y){
            return false;
        }
        else{
            return true;
        }
    }

    else{
        return false;
    }
}
