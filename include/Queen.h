#ifndef QUEEN_H
#define QUEEN_H

#include "SlidingPiece.h"
#include "CombinedPiece.h"

class Queen : public SlidingPiece, public CombinedPiece {
public:
    Queen(std::string color, int x, int y);
    Queen(const Queen& other);

    char getSymbol() const override;

    bool canMoveStraightOrDiagonal(int x, int y) const override;
    bool canMoveTo(int x, int y) const override;

    void printInfo() const override;
};

#endif
