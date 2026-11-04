#include "JumpingPiece.h"
#include <cstdlib>

JumpingPiece::JumpingPiece(std::string color, int x, int y)
    : ChessPiece(color, x, y) {
}

JumpingPiece::JumpingPiece(const JumpingPiece& other)
    : ChessPiece(other) {
}

bool JumpingPiece::canMoveTo(int newX, int newY) const {
    if (newX < 0 || newX > 7 ||
        newY < 0 || newY > 7)
        return false;

    int dx = std::abs(newX - x);
    int dy = std::abs(newY - y);

    return (dx == 2 && dy == 1) ||
           (dx == 1 && dy == 2);
}

void JumpingPiece::printInfo() const {
    ChessPiece::printInfo();
    std::cout << "Тип фигуры: Прыгающая\n";
}
