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
    ChessBoardSet chessBoard[8][8];
    QPushButton* previousClickedSquared = nullptr;
    QIcon icone_;
    int clickBoutonPiece = 0;
    int clickBoutonCase = 0;

    const QIcon whiteKnightPng = QIcon("./img/whiteKnight.png");
    const QIcon whiteRookPng = QIcon ("./img/whiteRook.png");
    const QIcon whiteKingPng = QIcon("./img/whiteKing.png");
    const QIcon blackKnightPng = QIcon("./img/blackKnight.png");
    const QIcon blackRookPng = QIcon("./img/blackRook.png");
    const QIcon blackKingPng = QIcon("./img/blackKing.png");
};

}
