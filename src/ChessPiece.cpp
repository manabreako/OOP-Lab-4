#include "ChessPiece.h"

int ChessPiece::whiteCount = 0;
int ChessPiece::blackCount = 0;

ChessPiece::ChessPiece(std::string color, int x, int y)
    : color(color), x(x), y(y) {

    if (color == "White")
        whiteCount++;
    else if (color == "Black")
        blackCount++;
}

ChessPiece::ChessPiece(const ChessPiece& other)
    : color(other.color), x(other.x), y(other.y) {

    if (color == "White")
        whiteCount++;
    else if (color == "Black")
        blackCount++;
}

ChessPiece::~ChessPiece() {
    if (color == "White")
        whiteCount--;
    else if (color == "Black")
        blackCount--;
}

ChessPiece& ChessPiece::operator=(const ChessPiece& other) {
    if (this != &other) {
        if (color != other.color) {
            if (color == "White")
                whiteCount--;
            else if (color == "Black")
                blackCount--;

            if (other.color == "White")
                whiteCount++;
            else if (other.color == "Black")
                blackCount++;
        }

        color = other.color;
        x = other.x;
        y = other.y;
    }

    return *this;
}

void ChessPiece::printInfo() const {
    std::cout << "Цвет: "
              << (color == "White" ? "Белый" : "Чёрный")
              << "\nПозиция: (" << x << ", " << y << ")\n";
}

std::string ChessPiece::getColor() const {
    return color;
}

int ChessPiece::getX() const {
    return x;
}

int ChessPiece::getY() const {
    return y;
}

int ChessPiece::getWhiteCount() {
    return whiteCount;
}

int ChessPiece::getBlackCount() {
    return blackCount;
}

bool ChessPiece::validateBoardState() {
    return whiteCount >= 0 && whiteCount <= 16 &&
           blackCount >= 0 && blackCount <= 16;
}

std::ostream& operator<<(std::ostream& out,
                         const ChessPiece& piece) {
    out << piece.getSymbol() << " "
        << (piece.color == "White" ? "Белый" : "Чёрный")
        << " (" << piece.x << ", " << piece.y << ")";

    return out;
}
