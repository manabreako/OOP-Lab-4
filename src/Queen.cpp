#include "Queen.h"

Queen::Queen(std::string color, int x, int y)
    : SlidingPiece(color, x, y, true, true) {
}

Queen::Queen(const Queen& other)
    : SlidingPiece(other) {
}

char Queen::getSymbol() const {
    return 'Q';
}

bool Queen::canMoveStraightOrDiagonal(int x, int y) const {
    return SlidingPiece::canMoveTo(x, y);
}

bool Queen::canMoveTo(int x, int y) const {
    return canMoveStraightOrDiagonal(x, y);
}

void Queen::printInfo() const {
    ChessPiece::printInfo();
    std::cout << "Тип фигуры: Ферзь\n";
}
