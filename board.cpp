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
                board[i][j] = new Square(Color::White, pos);
            }
            else {
                board[i][j] = new Square(Color::Black, pos);
            }
        }

    }
}

Square* Board::getSquare(Position pos) {
    return board[pos.x][pos.y];
}

piece::PiecesAbs* Board::getPiece(Position pieceLocationBoard) {
    if (board[pieceLocationBoard.x][pieceLocationBoard.y] != nullptr) {
        return board[pieceLocationBoard.x][pieceLocationBoard.y]->getPieceSquare();
    }
    return nullptr;
}

bool Board::isMovementAccepted(Position initial, Position destination) {
    PiecesAbs* pieceMoving = getPiece(initial);
    if (!pieceMoving) {
        std::cout << "No piece at the initial position." << std::endl;
        return false;
    }

    PiecesAbs* pieceDestination = getPiece(destination);
    // Check if the destination square has a piece of the same color
    if (pieceDestination && pieceDestination->getPieceType() == pieceMoving->getPieceType()) {
        std::cout << "Cannot capture your own piece." << std::endl;
        return false;
    }

    // Use the type-specific acceptedMovement method
    if (pieceMoving->acceptedMovement(destination)) {
        std::cout << "Movement is valid." << std::endl;
        // Optionally update board state here if the move is made
        return true;
    } else {
        std::cout << "Movement is not valid according to the piece's rules." << std::endl;
        return false;
    }
}
