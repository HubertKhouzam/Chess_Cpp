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
    bool acceptedMovement(Position caseArrive) override;
    PieceType getPieceType() const override;
private:
    PieceType nomPiece = PieceType::King;

    static int countKing_;
};


