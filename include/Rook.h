#ifndef ROOK_H
#define ROOK_H

#include "SlidingPiece.h"

class Rook : public SlidingPiece {
public:
    Rook(std::string color, int x, int y);
    Rook(const Rook& other);

    char getSymbol() const override;
    void printInfo() const override;
};

#endif
