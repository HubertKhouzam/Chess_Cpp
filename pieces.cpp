#include "pieces.h"

piece::PiecesAbs::PiecesAbs(Color color, Position position) {
    pieceColor_ = color;
    piecePosition_ = position;
}

piece::PiecesAbs::~PiecesAbs() {
}

Color piece::PiecesAbs::getPieceColor() {
    return pieceColor_;
}

Position piece::PiecesAbs::getPiecePosition() const {
    return piecePosition_;
}

bool piece::PiecesAbs::isMovementAccepted(Position coordonates) {
    return acceptedMovement(coordonates);
}

void piece::PiecesAbs::setPosition(Position coordo)
{
    piecePosition_ = coordo;

}

