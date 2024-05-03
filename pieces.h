#pragma once
#include "position.h"
#include "Color.h"
#include "TypePiece.h"
#include <string>
#include <iostream>

namespace piece {

class PiecesAbs
{
public:
    PiecesAbs() = default;
    PiecesAbs(Color color, Position position);
    virtual ~PiecesAbs();

    Color getPieceColor();
    Position getPiecePosition() const;
    void setPosition(Position coordonates);
    bool isMovementAccepted (Position coordonates);
    bool isCaptured = false;
    virtual bool acceptedMovement(Position caseArrive)= 0;
    // void incrementCountKing();
    // void decrementCountKing();
    // int getCountKing();
    virtual PieceType getPieceType() const = 0;

private:
    PieceType nomPiece = PieceType::None;
    Color pieceColor_;
    Position piecePosition_;
};
}

