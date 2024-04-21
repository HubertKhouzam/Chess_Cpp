#include "piecevisual.h"

PieceVisual::PieceVisual(string path, QString team, window::ChessBoard* chessboard)
{
    side = team;
    chessboard = chessboard;
    string path_ = path;
}

bool PieceVisual::isInBounds()
{
    bool isPossibleMove = false;
    if (position_.x >= 0 && position_.x < 8) {
        if (position_.y >= 0 && position_.y < 8) {
            isPossibleMove = true;
        }
    }
    return isPossibleMove;
}
