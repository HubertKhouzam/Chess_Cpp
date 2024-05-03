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
    else if(dynamic_cast<King*>(pieceMoving) != nullptr){
        King* pieceMovingType = dynamic_cast<King*>(pieceMoving);
        if (pieceMovingType->acceptedMovement(destination)) {
            std::cout << "Movement is valid." << std::endl;
            // pieceMoving->setPosition(destination);
            return true;
        } else {
            std::cout << "Movement is not valid according to the piece's movement rules." << std::endl;
            return false;
        }
    }
    else if(dynamic_cast<Rook*>(pieceMoving)){
        Rook* pieceMovingType = dynamic_cast<Rook*>(pieceMoving);
        if (pieceMovingType->acceptedMovement(destination)) {
            std::cout << "Movement is valid." << std::endl;
            // pieceMoving->setPosition(destination);
            return true;
        } else {
            std::cout << "Movement is not valid according to the piece's movement rules." << std::endl;
            return false;
        }
    }
    else if(dynamic_cast<Knight*>(pieceMoving)){
        Knight* pieceMovingType = dynamic_cast<Knight*>(pieceMoving);
        if (pieceMovingType->acceptedMovement(destination)) {
            std::cout << "Movement is valid." << std::endl;
            // pieceMoving->setPosition(destination);
            return true;
        } else {
            std::cout << "Movement is not valid according to the piece's movement rules." << std::endl;
            return false;
        }
    }
    else{
        std::cout << "Not the right piece type" << std::endl;
        return false;
    }

    std::cout << "Passé premier test" << std::endl;
    PiecesAbs* pieceDestination = getPiece(destination);
    // Vérifier si la destination est occupée par une pièce de la même couleur
    if (pieceDestination != nullptr && pieceDestination->getPieceColor() == pieceMoving->getPieceColor()) {
        std::cout << "Cannot move to a square occupied by a piece of the same color." << std::endl;
        return false;
    }
    std::cout << "Passé deuxieme test" << std::endl;
    // Vérifier si le mouvement est accepté selon les règles de la pièce

    std::cout << "Passé troisieme test" << std::endl;
}
