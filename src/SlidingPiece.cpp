/**
 * @file SlidingPiece.cpp
 * @brief Реализация промежуточного класса фигур с линейным перемещением.
 */

#include "SlidingPiece.h"
#include <cstdlib>

/**
 * @brief Создаёт фигуру и задаёт разрешённые направления перемещения.
 * @param color Цвет фигуры.
 * @param x Горизонтальная координата.
 * @param y Вертикальная координата.
 */
SlidingPiece::SlidingPiece(std::string color, int x, int y,
                           bool straight, bool diagonal)
    : ChessPiece(color, x, y),
      canMoveStraight(straight),
      canMoveDiagonal(diagonal) {
}

/**
 * @brief Копирует состояние и настройки перемещения фигуры.
 * @param other Объект, данные которого используются для копирования.
 */
SlidingPiece::SlidingPiece(const SlidingPiece& other)
    : ChessPiece(other),
      canMoveStraight(other.canMoveStraight),
      canMoveDiagonal(other.canMoveDiagonal) {
}

/**
 * @brief Проверяет прямую или диагональную геометрию хода и границы доски.
 * @param newX Целевая горизонтальная координата.
 * @param newY Целевая вертикальная координата.
 * @return true, если геометрия хода допустима; иначе false.
 * @warning Проверка не учитывает препятствия и занятые клетки.
 */
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

/**
 * @brief Выводит общую информацию о линейно перемещающейся фигуре.
 */
void SlidingPiece::printInfo() const {
    ChessPiece::printInfo();
    std::cout << "Тип фигуры: Скользящая\n";
}
