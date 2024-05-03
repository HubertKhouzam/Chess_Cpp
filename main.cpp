#include "chessboardWindow.h"

#include <QApplication>

#include "king.h"

#include "Color.h"

#include "position.h"

#include "menu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QIcon appIcon(":/img/gameIcon.jpeg");
    QApplication::setWindowIcon(appIcon);

    Menu menu;
    menu.show();
    return a.exec();


}

