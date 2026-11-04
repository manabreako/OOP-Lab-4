/**
 * @file ChessPiece.cpp
 * @brief Реализация базового класса шахматной фигуры.
 */

#include "ChessPiece.h"

int ChessPiece::whiteCount = 0;
int ChessPiece::blackCount = 0;

/**
 * @brief Инициализирует цвет и координаты фигуры и увеличивает соответствующий счётчик.
 * @param color Цвет фигуры.
 * @param x Горизонтальная координата.
 * @param y Вертикальная координата.
 */
ChessPiece::ChessPiece(std::string color, int x, int y)
    : color(color), x(x), y(y) {

    if (color == "White")
        whiteCount++;
    else if (color == "Black")
        blackCount++;
}

/**
 * @brief Копирует состояние фигуры и увеличивает счётчик её цвета.
 * @param other Объект, данные которого используются для копирования.
 */
ChessPiece::ChessPiece(const ChessPiece& other)
    : color(other.color), x(other.x), y(other.y) {

    if (color == "White")
        whiteCount++;
    else if (color == "Black")
        blackCount++;
}

/**
 * @brief Уменьшает счётчик фигур соответствующего цвета при уничтожении объекта.
 */
ChessPiece::~ChessPiece() {
    if (color == "White")
        whiteCount--;
    else if (color == "Black")
        blackCount--;
}

/**
 * @brief Копирует состояние другой фигуры с корректировкой счётчиков при изменении цвета.
 * @param other Фигура, данные которой присваиваются текущему объекту.
 * @return Ссылка на текущий объект.
 */
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

/**
 * @brief Выводит цвет и координаты фигуры.
 */
void ChessPiece::printInfo() const {
    std::cout << "Цвет: "
              << (color == "White" ? "Белый" : "Чёрный")
              << "\nПозиция: (" << x << ", " << y << ")\n";
}

/**
 * @brief Возвращает цвет фигуры.
 */
std::string ChessPiece::getColor() const {
    return color;
}

/**
 * @brief Возвращает координату X.
 */
int ChessPiece::getX() const {
    return x;
}

/**
 * @brief Возвращает координату Y.
 */
int ChessPiece::getY() const {
    return y;
}

/**
 * @brief Возвращает статический счётчик белых фигур.
 */
int ChessPiece::getWhiteCount() {
    return whiteCount;
}

/**
 * @brief Возвращает статический счётчик чёрных фигур.
 */
int ChessPiece::getBlackCount() {
    return blackCount;
}

/**
 * @brief Проверяет, что число фигур каждого цвета не превышает 16 и не является отрицательным.
 */
bool ChessPiece::validateBoardState() {
    return whiteCount >= 0 && whiteCount <= 16 &&
           blackCount >= 0 && blackCount <= 16;
}

/**
 * @brief Записывает символ, цвет и координаты фигуры в поток.
 */
std::ostream& operator<<(std::ostream& out,
                         const ChessPiece& piece) {
    out << piece.getSymbol() << " "
        << (piece.color == "White" ? "Белый" : "Чёрный")
        << " (" << piece.x << ", " << piece.y << ")";

    return out;
}
