#pragma once
#include "chessboardset.h"
#pragma warning(push, 0)
#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QLabel>
#include <QPixmap>
#include <QIcon>
#include "position.h"

namespace window{

class ChessBoard : public QMainWindow
{
    Q_OBJECT;
public:
    ChessBoard(QWidget* parent = nullptr);
    ~ChessBoard() override = default;

public slots:

    Position buttonSelected(int x, int y, QPushButton* button);
    void pieceSelected(QPushButton* button);
private:

    template <typename T = decltype(nullptr)>
    QPushButton* newButton(int i, int j);


    Position position_;
    QPushButton** chessBoard;
    QPushButton* previousClickedSquare = nullptr;
    QIcon icone_;
    int clickBoutonPiece = 0;
    int clickBoutonCase = 0;

    const QIcon whiteKnightPng = QIcon(":/img/W_KNIGHT.png");
    const QIcon whiteRookPng = QIcon (":/img/W_ROOK.png");
    const QIcon whiteKingPng = QIcon(":/img/W_KING.png");
    const QIcon blackKnightPng = QIcon(":/img/B_KNIGHT.png");
    const QIcon blackRookPng = QIcon(":/img/B_ROOK.png");
    const QIcon blackKingPng = QIcon(":/img/B_KING.png");
};

}
