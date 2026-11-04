#ifndef KNIGHT_H
#define KNIGHT_H

#include "JumpingPiece.h"

class Knight : public JumpingPiece {
public:
    Knight(std::string color, int x, int y);
    Knight(const Knight& other);

    char getSymbol() const override;
    void printInfo() const override;
};

#endif

