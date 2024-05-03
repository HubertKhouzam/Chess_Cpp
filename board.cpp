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

bool Board::isChecked(){
    for(int row = 0; row < dimension; row++){
        for (int col = 0; col < dimension; col++){
            Square* currentSquare = board[row][col];

            if (currentSquare->piece_->getPieceType() == PieceType::King){
                //Couleur du roi
                Color kingColor = currentSquare->piece_->getPieceColor();

                //Knight checks
                if ((board[row+2][col+1]->piece_->getPieceType() == PieceType::Knight && board[row+2][col+1]->piece_->getPieceColor() != kingColor) ||
                    (board[row+2][col-1]->piece_->getPieceType() == PieceType::Knight && board[row+2][col-1]->piece_->getPieceColor() != kingColor) ||
                    (board[row+1][col+2]->piece_->getPieceType() == PieceType::Knight && board[row+1][col+2]->piece_->getPieceColor() != kingColor) ||
                    (board[row+1][col-2]->piece_->getPieceType() == PieceType::Knight && board[row+1][col-2]->piece_->getPieceColor() != kingColor) ||
                    (board[row-1][col+2]->piece_->getPieceType() == PieceType::Knight && board[row-1][col+2]->piece_->getPieceColor() != kingColor) ||
                    (board[row-1][col-2]->piece_->getPieceType() == PieceType::Knight && board[row-1][col-2]->piece_->getPieceColor() != kingColor) ||
                    (board[row-2][col+1]->piece_->getPieceType() == PieceType::Knight && board[row-2][col+1]->piece_->getPieceColor() != kingColor) ||
                    (board[row-2][col-1]->piece_->getPieceType() == PieceType::Knight && board[row-2][col-1]->piece_->getPieceColor() != kingColor)){
                    return true;
                }

                //rook checks
                //top_direction
                for (int kingRow = row; kingRow>=0; kingRow--){
                    if ((board[kingRow][col]->piece_->getPieceType() != PieceType::Rook) || (board[kingRow][col]->piece_->getPieceColor() == kingColor)){
                        break;
                    }
                    if ((board[kingRow][col]->piece_->getPieceType() == PieceType::Rook) && (board[kingRow][col]->piece_->getPieceColor() != kingColor)){
                        return true;
                    }
                }
                //bottom_direction
                for (int kingRow = row; kingRow<dimension; kingRow++){
                    if ((board[kingRow][col]->piece_->getPieceType() != PieceType::Rook) || (board[kingRow][col]->piece_->getPieceColor() == kingColor)){
                        break;
                    }
                    if ((board[kingRow][col]->piece_->getPieceType() == PieceType::Rook) && (board[kingRow][col]->piece_->getPieceColor() != kingColor)){
                        return true;
                    }
                }
                //left_direction
                for (int kingCol = col; kingCol>=0; kingCol--){
                    if ((board[row][kingCol]->piece_->getPieceType() != PieceType::Rook) || (board[kingCol][col]->piece_->getPieceColor() == kingColor)){
                        break;
                    }
                    if ((board[row][kingCol]->piece_->getPieceType() == PieceType::Rook) && (board[kingCol][col]->piece_->getPieceColor() != kingColor)){
                        return true;
                    }
                }
                //right_direction
                for (int kingCol = col; kingCol<8; kingCol++){
                    if ((board[row][kingCol]->piece_->getPieceType() != PieceType::Rook) || (board[kingCol][col]->piece_->getPieceColor() == kingColor)){
                        break;
                    }
                    if ((board[row][kingCol]->piece_->getPieceType() == PieceType::Rook) && (board[kingCol][col]->piece_->getPieceColor() != kingColor)){
                        return true;
                    }
                }



            }

        }
    }
    return false;
}
