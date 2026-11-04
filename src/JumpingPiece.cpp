/**
 * @file JumpingPiece.cpp
 * @brief Реализация промежуточного класса фигур с прыжковым перемещением.
 */

#include "JumpingPiece.h"
#include <cstdlib>

/**
 * @brief Создаёт фигуру с прыжковым перемещением.
 * @param color Цвет фигуры.
 * @param x Горизонтальная координата.
 * @param y Вертикальная координата.
 */
JumpingPiece::JumpingPiece(std::string color, int x, int y)
    : ChessPiece(color, x, y) {
}

/**
 * @brief Копирует состояние фигуры с прыжковым перемещением.
 * @param other Объект, данные которого используются для копирования.
 */
JumpingPiece::JumpingPiece(const JumpingPiece& other)
    : ChessPiece(other) {
}

/**
 * @brief Проверяет ход по Г-образной траектории и границы доски.
 * @param newX Целевая горизонтальная координата.
 * @param newY Целевая вертикальная координата.
 * @return true, если геометрия хода допустима; иначе false.
 * @warning Проверка не учитывает препятствия и занятые клетки.
 */
bool JumpingPiece::canMoveTo(int newX, int newY) const {
    if (newX < 0 || newX > 7 ||
        newY < 0 || newY > 7)
        return false;

    int dx = std::abs(newX - x);
    int dy = std::abs(newY - y);

    return (dx == 2 && dy == 1) ||
           (dx == 1 && dy == 2);
}

/**
 * @brief Выводит общую информацию о прыгающей фигуре.
 */
void JumpingPiece::printInfo() const {
    ChessPiece::printInfo();
    std::cout << "Тип фигуры: Прыгающая\n";
}
