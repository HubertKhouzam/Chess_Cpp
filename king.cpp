#include "king.h"

King::King(Color color, Position coordinates) : piece::PiecesAbs(color,coordinates) {}
King::~King() {}
const std::string King::getPiece(){
    return "King";
}


bool King::acceptedMovement(Position caseArrive){
    if((caseArrive.x >= 0 && caseArrive.x < 8) && (caseArrive.y >= 0 && caseArrive.y < 8)){
        if((abs(caseArrive.x - getPiecePosition().x)) > 1  && (abs(caseArrive.y - getPiecePosition().y ) > 1)){
            return true;
        }
    }
    return false;

}
