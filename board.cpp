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

Square* Board::getSquare(Position pos) {
    return board[pos.x][pos.y].get();
}

piece::PiecesAbs* Board::getPiece(Position pieceLocationBoard) {
    if (board[pieceLocationBoard.x][pieceLocationBoard.y] != nullptr) {
        return board[pieceLocationBoard.x][pieceLocationBoard.y]->getPieceSquare();
    }
    return nullptr;
}

bool Board::isMovementAccepted(Position initial, Position destination) {
    PiecesAbs* pieceMoving = getPiece(initial);
    if (pieceMoving == nullptr) {
        std::cout << "No piece at the initial position." << std::endl;
        return false;
    }

    if (auto* king = dynamic_cast<King*>(pieceMoving)) {
        if (king->acceptedMovement(destination)) {
            std::cout << "Movement is valid." << std::endl;
            return true;
        }
    }
    else if (auto* rook = dynamic_cast<Rook*>(pieceMoving)) {
        if (rook->acceptedMovement(destination)) {
            std::cout << "Movement is valid." << std::endl;
            return true;
        }
    }
    else if (auto* knight = dynamic_cast<Knight*>(pieceMoving)) {
        if (knight->acceptedMovement(destination)) {
            std::cout << "Movement is valid." << std::endl;
            return true;
        }
    }
    else {
        std::cout << "Movement is not valid according to the piece's movement rules." << std::endl;
        return false;
    }

    std::cout << "Not the right piece type." << std::endl;
    return false;
}
