#pragma once
#include "board.h"
#include <iostream>


class RAIMouvement
{
public:
        RAIMouvement(PiecesAbs& piece, std::unique_ptr<Square>& destination);
        ~RAIMouvement();

    private:
        PiecesAbs& piece_;
        std::unique_ptr<Square>& destination_;
};


