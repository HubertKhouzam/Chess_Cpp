#ifndef ROOK_H
#define ROOK_H

#include "pieces.h"

class Rook: piece::PiecesAbs
{
public:
    Rook(Color color, Position coordo);
    ~Rook();
    bool acceptedMovement(Position coordo) override;

private:
    const virtual std::string getPiece() override;

};

#endif // ROOK_H
