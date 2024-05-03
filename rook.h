#ifndef ROOK_H
#define ROOK_H

#include "pieces.h"
#include "TypePiece.h"

class Rook: public piece::PiecesAbs
{
public:
    Rook(Color color, Position coordo);
    ~Rook();
    bool acceptedMovement(Position coordo) override;
    PieceType getPieceType() const override;
private:
    PieceType nomPiece = PieceType::Rook;
};

#endif // ROOK_H
