/**
 * @file Knight.cpp
 * @brief Реализация методов класса коня.
 */

#include "Knight.h"

/**
 * @brief Создаёт коня.
 * @param color Цвет фигуры.
 * @param x Горизонтальная координата.
 * @param y Вертикальная координата.
 */
Knight::Knight(std::string color, int x, int y)
    : JumpingPiece(color, x, y) {
}

/**
 * @brief Создаёт копию коня.
 * @param other Объект, данные которого используются для копирования.
 */
Knight::Knight(const Knight& other)
    : JumpingPiece(other) {
}

/**
 * @brief Возвращает символ N для коня.
 * @return Символьное обозначение фигуры.
 */
char Knight::getSymbol() const {
    return 'N';
}

/**
 * @brief Выводит цвет, координаты и тип фигуры.
 */
void Knight::printInfo() const {
    ChessPiece::printInfo();
    std::cout << "Тип фигуры: Конь\n";
}
