#include <QMessageBox>
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
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error!");
        msgBox.setText("Pas de pièce à la case initale");
        msgBox.setIcon(QMessageBox::Information);
        // Add buttons to the message box
        msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();
        return false;
    }

    if(pieceMoving->getPieceColor() != playerTurn_){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error!");
        msgBox.setText("Pas ton tour!");
        msgBox.setIcon(QMessageBox::Warning);
        // Add buttons to the message box
        msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();
        return false;
    }

    PiecesAbs* pieceDestination = getPiece(destination);
    // Check if the destination square has a piece of the same color
    if (pieceDestination && pieceDestination->getPieceColor() == pieceMoving->getPieceColor()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error!");
        msgBox.setText("Ne peut pas capturer une pièce de la même couleur");

        // Add buttons to the message box
        msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();
        return false;
    }

    // Use the type-specific acceptedMovement method
    if (pieceMoving->acceptedMovement(destination)) {
        std::cout << "Movement is valid." << std::endl;
        updateBoard(initial,destination);
        changeTurn();
        return true;
    } else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error!");
        msgBox.setText("Mouvement spécifique à la pièce invalide");

        // Add buttons to the message box
        msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();
        return false;
    }
}
