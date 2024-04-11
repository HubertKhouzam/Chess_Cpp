#ifndef CHESSBOARDWINDOW_H
#define CHESSBOARDWINDOW_H
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
private:
    const QIcon whiteBishopPng = QIcon("./img/whiteBishop.png");
    const QIcon whiteQueenPng = QIcon ("./img/whiteQueen.png");
    const QIcon whiteKingPng = QIcon("./img/whiteKing.png");
    const QIcon blackBishopPng = QIcon("./img/blackBishop.png");
    const QIcon blackQueenPng = QIcon("./img/blackQueen.png");
    const QIcon blackKingPng = QIcon("./img/blackKing.png");
};

#endif // CHESSBOARDWINDOW_H
}
