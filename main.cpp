#include "chessboardWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    window::ChessBoard w;
    w.show();
    return a.exec();
}

