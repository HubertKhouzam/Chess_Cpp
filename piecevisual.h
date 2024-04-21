#pragma once
#include "chessboardWindow.h"
#include <QApplication>
#include <QString>
#include "position.h"


class PieceVisual : public QObject
{
    Q_OBJECT

public:

    PieceVisual(string path, QString team, window::ChessBoard* chessboard); //pouvoir ajouter une piece facilement
    virtual void placePiece(int newXPos, int newYPos) = 0;

    const QString kingName = "King";
    const QString knightName = "Knight";
    const QString rookName = "Rook";

    bool isInBounds();


    ChessBoardSet* chessBoard;
    QString side;
    Position position_;
    QString name;
};


