#ifndef KNIGHT_H
#define KNIGHT_H

#include "pieces.h"

class Knight: piece::PiecesAbs
{
public:
    Knight(Color color, Position Coordo);
    ~Knight();

private:
    const virtual std::string getPiece() override;
    bool acceptedMovement(Position coordo) override;
};

#endif // KNIGHT_H
