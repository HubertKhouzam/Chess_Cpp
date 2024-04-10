#ifndef PIECES_H
#define PIECES_H

#include "position.h"
#include "color.h"
#include <string>

class PiecesAbs
{
public:
    PiecesAbs() = default;
    //PieceAbs() = (Color color, Position position)
    virtual ~PiecesAbs();

    Color getPieceColor();
    Position getPiecePosition() const;
    void setPosition(Position coordonates);
    const virtual std::string getPiece() = 0 ;
    bool isMovementAcepted (Position coordonates);
    bool isCaptured = false;

private:
    virtual bool acceptedMovement(Position coordobates)= 0;
    Color pieceColor_;
    Position piecePosition_;
};

#endif // PIECES_H
