#ifndef PIECES_H
#define PIECES_H

#include "position.h"
#include "color.h"
#include <string>

class PiecesAbs
{
public:
    PiecesAbs() = default;
    virtual ~PiecesAbs();

    Color getPieceColor();
    Position getPiecePosition() const;
    void setPosition(Position coordonates);
    const virtual std::string getPiece() = 0 ;

private:
    Color pieceColor_;
    Position piecePosition_;
};

#endif // PIECES_H
