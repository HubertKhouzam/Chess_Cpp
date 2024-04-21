#include "chessboardset.h"



// slots:

void ChessBoardSet::changerValeur(int valeur) {
    if (valeur != valeur_) {
        valeur_ = valeur;
        emit valeurChangee(valeur_);
    }
}
void ChessBoardSet::effacer() {
    operation_ = egal; changerValeur(0);
}


void ChessBoardSet::ajouterChiffre(int chiffre) {
    if (estResultat_) {
        valeur_ = 0;
        estResultat_ = false;
    }
    changerValeur(valeur_ * 10 + chiffre);
}

void ChessBoardSet::changerOperation(const function<int(int, int)>& operation) {
    if (!estResultat_)
        effectuerOperation();
    operation_ = operation;
}

void ChessBoardSet::operationPlus()  { changerOperation(plus); }
void ChessBoardSet::operationMoins() { changerOperation(moins); }
void ChessBoardSet::operationEgal()  { changerOperation(egal); }

void ChessBoardSet::effectuerOperation() {
    resultatPrecedent_ = operation_(resultatPrecedent_, valeur_);
    estResultat_ = true;
    changerValeur(resultatPrecedent_);
}

// Fonctions pour l'opération:
// (on aurait pu à la place mettre des lambdas dans operationPlus() ...)
int ChessBoardSet::plus (int x, int y) { return x + y; }
int ChessBoardSet::moins(int x, int y) { return x - y; }
int ChessBoardSet::egal (int  , int y) { return y; }
