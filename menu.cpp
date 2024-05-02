#include "menu.h"
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QPushButton>
#include <Qlabel>

Menu::Menu(QWidget *parent): QMainWindow(parent)
{
    QVBoxLayout *layoutPrincipal = new QVBoxLayout;

    QLabel *messageLabel = new QLabel("Veuillez choisir une position initiale de partie d'échecs.");
    messageLabel->setAlignment(Qt::AlignCenter);
    layoutPrincipal->addWidget(messageLabel);

    QPushButton *buttonPosition1 = new QPushButton("Classique");
    QPushButton *buttonPosition2 = new QPushButton("Position 2");
    QPushButton *buttonPosition3 = new QPushButton("Position 3");

    connect(buttonPosition1, &QPushButton::clicked, this, [this]() { positionSelected("Classique"); });
    connect(buttonPosition2, &QPushButton::clicked, this, [this]() { positionSelected("Position 2"); });
    connect(buttonPosition3, &QPushButton::clicked, this, [this]() { positionSelected("Position 3"); });

    layoutPrincipal->addWidget(buttonPosition1);
    layoutPrincipal->addWidget(buttonPosition2);
    layoutPrincipal->addWidget(buttonPosition3);

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layoutPrincipal);

    setCentralWidget(centralWidget);

    setWindowTitle("Chess Game");
    resize(600, 400);

}



Menu::~Menu(){}

void Menu::positionSelected(const QString &position)
{

}
