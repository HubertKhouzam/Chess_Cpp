#pragma once
#include "square.h"

class Board
{
public:
    Board();
    virtual ~Board() = default;
    bool isMovementAccepted(Position initial, Position destination);
    piece::PiecesAbs* getPiece(Position pieceLocationBoard);
    std::unique_ptr<Square>* getSquare(Position pos);

private:

    static const int dimension = 8;
    std::unique_ptr<Square> board[8][8];

};

