#pragma once
#include "square.h"
#include <QMessageBox>

class Board
{
public:
    Board();
    virtual ~Board() = default;
    bool isMovementAccepted(Position initial, Position destination);
    bool verifIsMovementAccepted(Position initial, Position destination);
    piece::PiecesAbs* getPiece(Position pieceLocationBoard);
    Square* getSquare(Position pos);
    void updateBoard(Position depart, Position dest);
    void changeTurn();
    bool isInBounds(int row, int col);
    bool isChecked(Color kingColor);
    std::vector<Position> possibleMovements(Position realPos);



private:

    static const int dimension = 8;
    Square* board[8][8];
    Color playerTurn_ = Color::White;

};

