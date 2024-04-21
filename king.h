#pragma once
#include "pieces.h"

class King : piece::PiecesAbs
{
public:
    King(Color color, Position coordinates);
    virtual ~King();

private:
    const virtual std::string getPiece() override;
    bool acceptedMovement(Position caseArrive) override;

};


