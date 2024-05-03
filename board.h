#pragma once
#include "square.h"

class Board
{
public:
    Board();
    virtual ~Board() = default;
    bool isMovementAccepted(Position initial, Position destination);
    piece::PiecesAbs* getPiece(Position pieceLocationBoard);
    Square* getSquare(Position pos);
    void updateBoard(Position depart, Position dest);
    void changeTurn();

private:

    static const int dimension = 8;
    Square* board[8][8];
    Color playerTurn_ = Color::White;
};

