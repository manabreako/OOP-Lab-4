#include "Rook.h"

Rook::Rook(std::string color, int x, int y)
    : SlidingPiece(color, x, y, true, false) {
}

Rook::Rook(const Rook& other)
    : SlidingPiece(other) {
}

char Rook::getSymbol() const {
    return 'R';
}

void Rook::printInfo() const {
    ChessPiece::printInfo();
    std::cout << "Тип фигуры: Ладья\n";
}
