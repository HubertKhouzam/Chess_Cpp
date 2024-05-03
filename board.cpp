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

void Board::changeTurn(){
    playerTurn_ = playerTurn_ == Color::White ?  Color::Black : Color::White;
}


void Board::updateBoard(Position depart, Position dest){
    Square* destination = getSquare(dest);
    PiecesAbs* initial = getSquare(depart)->getPieceSquare();
    destination->setUnoccupiedSquare();
    destination->setPieceSquare(initial);
    getSquare(depart)->setUnoccupiedSquare();
}

bool Board::isMovementAccepted(Position initial, Position destination) {
    PiecesAbs* pieceMoving = getPiece(initial);
    if (!pieceMoving) {
        std::cout << "No piece at the initial position." << std::endl;
        return false;
    }

    if(pieceMoving->getPieceColor() != playerTurn_){
        std::cout << "Not your turn" << std::endl;
        return false;
    }

    PiecesAbs* pieceDestination = getPiece(destination);
    // Check if the destination square has a piece of the same color
    if (pieceDestination && pieceDestination->getPieceColor() == pieceMoving->getPieceColor()) {
        std::cout << "Cannot capture your own piece." << std::endl;
        return false;
    }

    // Use the type-specific acceptedMovement method
    if (pieceMoving->acceptedMovement(destination)) {
        std::cout << "Movement is valid." << std::endl;
        updateBoard(initial,destination);
        changeTurn();
        return true;
    } else {
        std::cout << "Movement is not valid according to the piece's rules." << std::endl;
        return false;
    }
}
