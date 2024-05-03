#include "menu.h"
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QPushButton>
#include <Qlabel>
#include "chessboardWindow.h"

Menu::Menu(QWidget *parent): QMainWindow(parent)
{
    QVBoxLayout *layoutPrincipal = new QVBoxLayout;

    QLabel *messageLabel = new QLabel("Veuillez choisir une position initiale de partie d'échecs.");
    messageLabel->setAlignment(Qt::AlignCenter);
    layoutPrincipal->addWidget(messageLabel);

    QPushButton *buttonClassique = new QPushButton("Classique");
    QPushButton *buttonPosition2 = new QPushButton("Position 2");
    QPushButton *buttonPosition3 = new QPushButton("Position 3");

    connect(buttonClassique, &QPushButton::clicked, this, [this]() { positionSelected("Classique"); });
    connect(buttonPosition2, &QPushButton::clicked, this, [this]() { positionSelected("Position 2"); });
    connect(buttonPosition3, &QPushButton::clicked, this, [this]() { positionSelected("Position 3"); });

    layoutPrincipal->addWidget(buttonClassique);
    layoutPrincipal->addWidget(buttonPosition2);
    layoutPrincipal->addWidget(buttonPosition3);

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layoutPrincipal);

    setCentralWidget(centralWidget);

    setWindowTitle("Chess Game");
    resize(600, 400);

}



Menu::~Menu(){}

void Menu::positionSelected(const std::string &position)
{

    window::ChessBoard*  w = new window::ChessBoard(position);
    w->show();
    this->close();
}
