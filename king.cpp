#include "king.h"

int King::countKing_ = 0;

King::King(Color color, Position coordinates) : piece::PiecesAbs(color,coordinates) {
    if (getCountKing() >= 2){
        throw std::runtime_error("Il ne peut y avoir plus de deux rois sur un échiquier.");
    }

    incrementCountKing();
}

King::~King() {
    decrementCountKing();
}

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

void King::incrementCountKing(){
    ++countKing_;
}

void King::decrementCountKing(){
    --countKing_;
}

int King::getCountKing(){
    return countKing_;
}
