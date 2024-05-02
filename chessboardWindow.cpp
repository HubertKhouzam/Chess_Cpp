#include "chessboardWindow.h"
#pragma warning(push, 0)
#include <QGridLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QLabel>
#include <QString>
#include <QVariant>
#include <QMenu>
#include <QMenuBar>
#pragma pop()
#pragma pop()


using namespace std;



template <typename T>
QPushButton *window::ChessBoard::newButton(int i, int j)
{
    auto button = new QPushButton(this);
    button->setFixedSize(100, 100);

    if constexpr (!is_same_v<T, decltype(nullptr)>)
        QObject::connect(button, &QPushButton::clicked, &chessBoard, [this, i, j, button]()
                         { buttonSelected(i, j, button); });
    return button;
}

window::ChessBoard::ChessBoard(QWidget *parent) : QMainWindow(parent)
{
    auto widgetPrincipal = new QWidget(this);
    auto layoutPrincipal = new QVBoxLayout(widgetPrincipal);

    auto layout = new QGridLayout();
    layout->setSpacing(0); // Réduit l'espace entre les boutons à 0
    layoutPrincipal->addLayout(layout);

    chessBoard = new QPushButton*[8];
    for (int i = 0; i < 8; i++) {
        chessBoard[i] = new QPushButton[8];
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            QPushButton* button = &chessBoard[i][j];
            button->setStyleSheet((i + j) % 2 == 0 ? "background-color: white;" : "background-color: grey;");
            QObject::connect(button, &QPushButton::clicked, this, [this, i, j, button]() {
                buttonSelected(i, j, button);
            });
            layout->addWidget(button, i, j);
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);  // Permet aux boutons de s'adapter à la taille disponible
        }
    }

    chessBoard[3][6].setIcon(whiteKingPng);
    chessBoard[3][6].setIconSize(QSize(80, 80));


    widgetPrincipal->setLayout(layoutPrincipal);
    setCentralWidget(widgetPrincipal);
    setWindowTitle("Echiquier");

    QAction *exit = new QAction(tr("E&xit"), this);
    // On connecte le clic sur ce bouton avec l'action de clore le programme
    connect(exit, SIGNAL(triggered()), this, SLOT(close()));


    QMenu *menuMenu = menuBar()->addMenu(tr("&Menu"));
    // Dans lequel on ajoute notre bouton 'Exit'
    menuMenu->addAction(exit);
}

Position window::ChessBoard::buttonSelected(int x_, int y_, QPushButton *button)
{
    Position pos {x_, y_};

    if (clickBoutonCase == 1 && button->icon().isNull()) { // a changer condition

        previousClickedSquare->setIcon(QIcon());
        button->setIcon(icone_);
        button->setIconSize(QSize(80,80));
        previousClickedSquare = nullptr;
        clickBoutonCase = 0;
    } else if (!button->icon().isNull()) {
        icone_ = button->icon();
        previousClickedSquare = button;
        clickBoutonCase = 1;
    }

    return pos;
}

void window::ChessBoard::pieceSelected(QPushButton *button)
{
    clickBoutonPiece = 1;
    clickBoutonCase = 0;
    icone_ = button->icon();
    // return button;
}
