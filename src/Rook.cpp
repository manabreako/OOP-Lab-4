/**
 * @file Rook.cpp
 * @brief Реализация методов класса ладьи.
 */

#include "Rook.h"

/**
 * @brief Создаёт ладью с прямым перемещением.
 * @param color Цвет фигуры.
 * @param x Горизонтальная координата.
 * @param y Вертикальная координата.
 */
Rook::Rook(std::string color, int x, int y)
    : SlidingPiece(color, x, y, true, false) {
}

/**
 * @brief Создаёт копию ладьи.
 * @param other Объект, данные которого используются для копирования.
 */
Rook::Rook(const Rook& other)
    : SlidingPiece(other) {
}

/**
 * @brief Возвращает символ R для ладьи.
 * @return Символьное обозначение фигуры.
 */
char Rook::getSymbol() const {
    return 'R';
}

/**
 * @brief Выводит цвет, координаты и тип фигуры.
 */
void Rook::printInfo() const {
    ChessPiece::printInfo();
    std::cout << "Тип фигуры: Ладья\n";
}
