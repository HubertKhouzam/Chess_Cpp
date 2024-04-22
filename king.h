#pragma once
#include "pieces.h"

class King : piece::PiecesAbs
{
public:
    King(Color color, Position coordinates);
    virtual ~King();

    void incrementCountKing();
    void decrementCountKing();
    int getCountKing();

private:
    const virtual std::string getPiece() override;
    bool acceptedMovement(Position caseArrive) override;

    static int countKing_;
};


