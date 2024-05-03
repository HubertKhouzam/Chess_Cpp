#include "board.h"
#include "knight.h"
#include "king.h"
#include "rook.h"

using namespace piece;

Board::Board() {

    for (int i = 0 ; i < dimension ; i++)
    {
        for (int j = 0 ; j < dimension ; j++)
        {
            Position pos;
            pos.x = i;
            pos.y = j;
            if((i+j)% 2 == 0) {
                board[i][j] = std::make_unique<Square>(Square(Color::White, pos));
            }
            else {
                board[i][j] = std::make_unique<Square>(Square(Color::Black, pos));
            }
        }

    }
}

std::unique_ptr<Square>* Board::getSquare(Position pos) {
    return &board[pos.x][pos.y];
}

piece::PiecesAbs* Board::getPiece(Position pieceLocationBoard) {
    return board[pieceLocationBoard.x][pieceLocationBoard.y]->getPieceSquare();
}

bool Board::isMovementAccepted(Position initial, Position destination) {

    PiecesAbs* pieceMoving = getPiece(initial);
    PiecesAbs* pieceDestination = getPiece(destination);

    if ((pieceDestination == nullptr || (pieceDestination->getPieceColor() != pieceMoving->getPieceColor())) && pieceMoving->acceptedMovement(destination)) {

        std::cout << "yes1" << std::endl;
        //pieceMoving->setPosition(destination);
        std::cout << "yes2" << std::endl;
        return true;
    }
    else
        return false;
}
