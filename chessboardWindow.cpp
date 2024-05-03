#include "chessboardWindow.h"
#include "TypePiece.h"
#pragma warning(push, 0)
#include <QGridLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QLabel>
#include <QString>
#include <QVariant>
#include <QMenu>
#include <QMenuBar>
#include <QApplication>
#include <QMessageBox>
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

window::ChessBoard::ChessBoard(const std::string &position, QWidget *parent) : QMainWindow(parent)
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

    if(position=="Classique"){
    //whitePiece
        chessBoard[7][7].setIcon(whiteRookPng);
        chessBoard[7][7].setIconSize(QSize(80,80));
        gameBoard_.getSquare({7,7})->setPieceSquare(PieceType::Rook,Color::White);

        chessBoard[7][0].setIcon(whiteRookPng);
        chessBoard[7][0].setIconSize(QSize(80,80));
        gameBoard_.getSquare({7,0})->setPieceSquare(PieceType::Rook,Color::White);


        chessBoard[7][4].setIcon(whiteKingPng);
        chessBoard[7][4].setIconSize(QSize(80,80));
        gameBoard_.getSquare({7,4})->setPieceSquare(PieceType::King,Color::White);


        chessBoard[7][6].setIcon(whiteKnightPng);
        chessBoard[7][6].setIconSize(QSize(80,80));
        gameBoard_.getSquare({7,6})->setPieceSquare(PieceType::Knight,Color::White);


        chessBoard[7][1].setIcon(whiteKnightPng);
        chessBoard[7][1].setIconSize(QSize(80,80));
        gameBoard_.getSquare({7,1})->setPieceSquare(PieceType::Knight,Color::White);


    //BlackPiece
        chessBoard[0][7].setIcon(blackRookPng);
        chessBoard[0][7].setIconSize(QSize(80,80));
        gameBoard_.getSquare({0,7})->setPieceSquare(PieceType::Rook,Color::Black);


        chessBoard[0][0].setIcon(blackRookPng);
        chessBoard[0][0].setIconSize(QSize(80,80));
        gameBoard_.getSquare({0,0})->setPieceSquare(PieceType::Rook,Color::Black);


        chessBoard[0][4].setIcon(blackKingPng);
        chessBoard[0][4].setIconSize(QSize(80,80));
        gameBoard_.getSquare({0,4})->setPieceSquare(PieceType::King,Color::Black);


        chessBoard[0][6].setIcon(blackKnightPng);
        chessBoard[0][6].setIconSize(QSize(80,80));
        gameBoard_.getSquare({0,6})->setPieceSquare(PieceType::Knight,Color::Black);


        chessBoard[0][1].setIcon(blackKnightPng);
        chessBoard[0][1].setIconSize(QSize(80,80));
        gameBoard_.getSquare({0,1})->setPieceSquare(PieceType::Knight,Color::Black);

    }
    else if (position=="Position 2"){
        //whitePiece
        chessBoard[2][3].setIcon(whiteRookPng);
        chessBoard[2][3].setIconSize(QSize(80,80));
        gameBoard_.getSquare({2,3})->setPieceSquare(PieceType::Rook,Color::White);


        chessBoard[2][4].setIcon(whiteKingPng);
        chessBoard[2][4].setIconSize(QSize(80,80));
        gameBoard_.getSquare({2,4})->setPieceSquare(PieceType::King,Color::White);


        chessBoard[3][3].setIcon(whiteKnightPng);
        chessBoard[3][3].setIconSize(QSize(80,80));
        gameBoard_.getSquare({3,3})->setPieceSquare(PieceType::Knight,Color::White);



        //BlackPiece

        chessBoard[5][5].setIcon(blackKingPng);
        chessBoard[5][5].setIconSize(QSize(80,80));
        gameBoard_.getSquare({5,5})->setPieceSquare(PieceType::King,Color::Black);


        chessBoard[4][4].setIcon(blackKnightPng);
        chessBoard[4][4].setIconSize(QSize(80,80));
        gameBoard_.getSquare({4,4})->setPieceSquare(PieceType::Knight,Color::Black);

    }

    else if (position=="Position 3"){

        //whitePiece
        chessBoard[2][3].setIcon(whiteKnightPng);
        chessBoard[2][3].setIconSize(QSize(80,80));
        gameBoard_.getSquare({2,3})->setPieceSquare(PieceType::Knight,Color::White);


        chessBoard[2][4].setIcon(whiteKingPng);
        chessBoard[2][4].setIconSize(QSize(80,80));
        gameBoard_.getSquare({2,4})->setPieceSquare(PieceType::King,Color::White);


        chessBoard[3][4].setIcon(whiteKnightPng);
        chessBoard[3][4].setIconSize(QSize(80,80));
        gameBoard_.getSquare({3,4})->setPieceSquare(PieceType::Knight,Color::White);


        chessBoard[1][3].setIcon(whiteKnightPng);
        chessBoard[1][3].setIconSize(QSize(80,80));
        gameBoard_.getSquare({1,3})->setPieceSquare(PieceType::Knight,Color::White);


        chessBoard[3][7].setIcon(whiteKnightPng);
        chessBoard[3][7].setIconSize(QSize(80,80));
        gameBoard_.getSquare({3,7})->setPieceSquare(PieceType::Knight,Color::White);


        chessBoard[3][5].setIcon(whiteKnightPng);
        chessBoard[3][5].setIconSize(QSize(80,80));
        gameBoard_.getSquare({3,5})->setPieceSquare(PieceType::Knight,Color::White);


        //BlackPiece

        chessBoard[0][0].setIcon(blackKingPng);
        chessBoard[0][0].setIconSize(QSize(80,80));
        gameBoard_.getSquare({0,0})->setPieceSquare(PieceType::King,Color::Black);


        chessBoard[4][4].setIcon(blackRookPng);
        chessBoard[4][4].setIconSize(QSize(80,80));
        gameBoard_.getSquare({4,4})->setPieceSquare(PieceType::Rook,Color::Black);


    }


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

    //gameBoard_.getSquare(previousPosition)

    if (clickBoutonCase == 1 && button->icon().isNull()) { // a changer condition
        std::cout<<"yoho"<<std::endl;
        if (gameBoard_.isMovementAccepted(previousPosition,pos)){
            std::cout<<"yoho"<<std::endl;
            previousClickedSquare->setIcon(QIcon());  //second click, drop piece
            button->setIcon(icone_);
            button->setIconSize(QSize(80,80));
            previousClickedSquare = nullptr;
        }
        else {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Position invalide");
            msgBox.setText("Hello, this is a pop-up message!");

            // Add buttons to the message box
            msgBox.addButton(QMessageBox::Ok);
        }

        clickBoutonCase = 0;
    } else if (!button->icon().isNull()) {    //first click, select piece
        icone_ = button->icon();
        previousClickedSquare = button;
        clickBoutonCase = 1;
        previousPosition = pos;

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
