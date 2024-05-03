#ifndef KNIGHT_H
#define KNIGHT_H

#include "pieces.h"
#include "TypePiece.h"

class Knight: public piece::PiecesAbs
{
public:
    Knight(Color color, Position Coordo);
    ~Knight();
    bool acceptedMovement(Position coordo) override;
    PieceType getPieceType() const override;
private:
    PieceType nomPiece = PieceType::Knight;
};





#endif // KNIGHT_H
