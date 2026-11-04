#include "Bishop.h"

Bishop::Bishop(std::string color, int x, int y)
    : SlidingPiece(color, x, y, false, true) {
}

Bishop::Bishop(const Bishop& other)
    : SlidingPiece(other) {
}

char Bishop::getSymbol() const {
    return 'B';
}

void Bishop::printInfo() const {
    ChessPiece::printInfo();
    std::cout << "Тип фигуры: Слон\n";
}
