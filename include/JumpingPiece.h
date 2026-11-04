/**
 * @file JumpingPiece.h
 * @brief Объявление промежуточного класса фигур с прыжковым перемещением.
 */

#ifndef JUMPINGPIECE_H
#define JUMPINGPIECE_H

#include "ChessPiece.h"

/**
 * @class JumpingPiece
 * @brief Промежуточный класс шахматных фигур, перемещающихся прыжком. Реализует проверку хода по Г-образной траектории.
 */
class JumpingPiece : public ChessPiece {
public:
/**
 * @brief Создаёт фигуру с прыжковым перемещением.
 * @param color Цвет фигуры.
 * @param x Горизонтальная координата.
 * @param y Вертикальная координата.
 */
    JumpingPiece(std::string color, int x, int y);
/**
 * @brief Создаёт копию фигуры с прыжковым перемещением.
 * @param other Копируемая фигура.
 */
    JumpingPiece(const JumpingPiece& other);

/**
 * @brief Проверяет возможность прыжкового перемещения на заданную клетку.
 * @param x Целевая горизонтальная координата.
 * @param y Целевая вертикальная координата.
 * @return true, если ход соответствует Г-образной траектории и остаётся в пределах доски.
 */
    bool canMoveTo(int x, int y) const override;
/**
 * @brief Выводит общую информацию о прыгающей фигуре.
 */
    void printInfo() const override;
};

#endif
