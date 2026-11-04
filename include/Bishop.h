#ifndef BISHOP_H
#define BISHOP_H

#include "SlidingPiece.h"

class Bishop : public SlidingPiece {
public:
    Bishop(std::string color, int x, int y);
    Bishop(const Bishop& other);

    char getSymbol() const override;
    void printInfo() const override;
};

#endif
