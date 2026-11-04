
#ifndef SLIDINGPIECE_H
#define SLIDINGPIECE_H

#include "ChessPiece.h"

class SlidingPiece : public ChessPiece {
protected:
    bool canMoveStraight;
    bool canMoveDiagonal;

public:
    SlidingPiece(std::string color, int x, int y,
                 bool straight, bool diagonal);

    SlidingPiece(const SlidingPiece& other);

    bool canMoveTo(int x, int y) const override;
    void printInfo() const override;
};

#endif
