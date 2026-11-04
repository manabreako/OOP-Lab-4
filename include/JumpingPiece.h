#ifndef JUMPINGPIECE_H
#define JUMPINGPIECE_H

#include "ChessPiece.h"

class JumpingPiece : public ChessPiece {
public:
    JumpingPiece(std::string color, int x, int y);
    JumpingPiece(const JumpingPiece& other);

    bool canMoveTo(int x, int y) const override;
    void printInfo() const override;
};

#endif
