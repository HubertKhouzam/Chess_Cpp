#pragma once
#include "position.h"
#include "Color.h"
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
    const virtual std::string getPiece() = 0 ;
    bool isMovementAccepted (Position coordonates);
    bool isCaptured = false;
    virtual bool acceptedMovement(Position caseArrive)= 0;
    // void incrementCountKing();
    // void decrementCountKing();
    // int getCountKing();

private:

    Color pieceColor_;
    Position piecePosition_;
};
}

