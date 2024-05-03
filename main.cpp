#include "chessboardWindow.h"

#include <QApplication>

#include "king.h"

#include "Color.h"

#include "position.h"

#include "menu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu menu;
    menu.show();
    return a.exec();


}

