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
// ui(new Ui::ChessBoard)
{
    // Si on objet n'a pas encore de parent on lui met "this" comme parent en attendant, si possible, pour s'assurer que tous les pointeurs sont gérés par un delete automatique en tout temps sans utiliser de unique_ptr.

    auto widgetPrincipal = new QWidget(this);
    auto layoutPrincipal = new QVBoxLayout(widgetPrincipal); // Donner un parent à un layout est comme un setLayout.

    // Version avec setProperty:
    {
        auto layout = new QGridLayout();
        layoutPrincipal->addLayout(layout);

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                auto button = newButton(i, j);
                // On donne un nom à la propriété, et on lui donne une valeur QVariant (comme dans les notes de cours) d'un type quelconque (doit enregistrer le type avec Q_DECLARE_METATYPE(LeType) si ce n'est pas un type déjà connu de Qt).
                if ((i + j) % 2 == 0)
                {
                    button->setStyleSheet("background-color:white");
                }
                else
                {
                    button->setStyleSheet("background-color:grey");
                }
                QObject::connect(button, &QPushButton::clicked, this, [this, i, j, button]()
                                 { buttonSelected(i, j, button); });
                layout->addWidget(button, i, j);
            }
        }


        layoutPrincipal->addLayout(layout);

        widgetPrincipal->setLayout(layoutPrincipal);
        widgetPrincipal->setFixedSize(850, 850);

        setCentralWidget(widgetPrincipal);
        setWindowTitle("Echiquier");

        QAction *exit = new QAction(tr("E&xit"), this);
        // On connecte le clic sur ce bouton avec l'action de clore le programme
        connect(exit, SIGNAL(triggered()), this, SLOT(close()));


        QMenu *menuMenu = menuBar()->addMenu(tr("&Menu"));
        // Dans lequel on ajoute notre bouton 'Exit'
        menuMenu->addAction(exit);
    }

    setCentralWidget(widgetPrincipal);
    setWindowTitle("Chess");
}

Position window::ChessBoard::buttonSelected(int x_, int y_, QPushButton *button)
{
    Position pos;
    pos.x = x_;
    pos.y = y_;

    //std::cout << pos.x << pos.y << std::endl;
    clickBoutonCase++;
    if (clickBoutonCase == 1 && clickBoutonPiece == 1)
    {
        button->setIcon(icone_);
        button->setIconSize(QSize(80, 80));
        clickBoutonCase = 0;
        clickBoutonPiece = 0;
    }
    else if (clickBoutonCase == 1)
    {

        if (button->text() == "")
        {
            clickBoutonCase = 0;
        }
        else
        {
            icone_ = button->icon();
            previousClickedSquared = button;
        }
    }
    else if (clickBoutonCase == 2)
    {

        if (previousClickedSquared != button)
        {
            button->setIcon(icone_);
            previousClickedSquared->setIcon(QIcon());
        }

        clickBoutonCase = 0;
        previousClickedSquared = nullptr;
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
