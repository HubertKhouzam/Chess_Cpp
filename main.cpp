#include "chessboardWindow.h"

#include <QApplication>

#include "king.h"

#include "Color.h"

#include "position.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    window::ChessBoard w;
    w.show();
    return a.exec();

    // Position position1;
    // position1.x = 2;
    // position1.y = 2;

    // Position position2;
    // position2.x = 3;
    // position2.y = 3;

    // Position position3;
    // position3.x = 4;
    // position3.y = 4;


    // Color white = White;
    // Color black = Black;

    // //std::cout << "yo";
    // King king1 = King(white, position1);
    // King king2 = King(black, position2);
    // King king3 = King(white, position3);
    // std::cout << "yo";
}

