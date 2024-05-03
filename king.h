#pragma once
#include "pieces.h"
#include "TypePiece.h"

class King : public piece::PiecesAbs
{
public:
    King(Color color, Position coordinates);
    virtual ~King();

    void incrementCountKing();
    void decrementCountKing();
    int getCountKing();
    virtual bool acceptedMovement(Position caseArrive) override;
    PieceType nomPiece = PieceType::King;
private:

    static int countKing_;
};


