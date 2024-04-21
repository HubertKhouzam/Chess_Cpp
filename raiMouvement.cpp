#include "raiMouvement.h"

RAIMouvement::RAIMouvement(PiecesAbs& piece, std::unique_ptr<Square>& destination) : piece_(piece), destination_(destination)
{
    std::cout << "l'objet est créé" << std::endl;
}

RAIMouvement::~RAIMouvement()
{
    piece_.isCaptured= true;
    destination_->piece_ = nullptr;
    std::cout << "L'objet est détruit" << std::endl;
}
