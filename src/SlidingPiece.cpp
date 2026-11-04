#include "SlidingPiece.h"
#include <cstdlib>

SlidingPiece::SlidingPiece(std::string color, int x, int y,
                           bool straight, bool diagonal)
    : ChessPiece(color, x, y),
      canMoveStraight(straight),
      canMoveDiagonal(diagonal) {
}

SlidingPiece::SlidingPiece(const SlidingPiece& other)
    : ChessPiece(other),
      canMoveStraight(other.canMoveStraight),
      canMoveDiagonal(other.canMoveDiagonal) {
}

bool SlidingPiece::canMoveTo(int newX, int newY) const {
    if (newX < 0 || newX > 7 ||
        newY < 0 || newY > 7)
        return false;

    if (newX == x && newY == y)
        return false;

    int dx = std::abs(newX - x);
    int dy = std::abs(newY - y);

    if (canMoveStraight && (dx == 0 || dy == 0))
        return true;

    if (canMoveDiagonal && dx == dy)
        return true;

    return false;
}

void SlidingPiece::printInfo() const {
    ChessPiece::printInfo();
    std::cout << "Тип фигуры: Скользящая\n";
}
