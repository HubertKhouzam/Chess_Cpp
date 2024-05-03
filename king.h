#pragma once
#include "pieces.h"

class King : public piece::PiecesAbs
{
public:
    King(Color color, Position coordinates);
    virtual ~King();

    void incrementCountKing();
    void decrementCountKing();
    int getCountKing();
    virtual bool acceptedMovement(Position caseArrive) override;

private:
    const virtual std::string getPiece() override;


    static int countKing_;
};


