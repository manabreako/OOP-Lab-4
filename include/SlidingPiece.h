/**
 * @file SlidingPiece.h
 * @brief Объявление промежуточного класса фигур с линейным перемещением.
 */


#ifndef SLIDINGPIECE_H
#define SLIDINGPIECE_H

#include "ChessPiece.h"

/**
 * @class SlidingPiece
 * @brief Промежуточный класс фигур с линейным перемещением. Позволяет настраивать прямые и диагональные ходы.
 */
class SlidingPiece : public ChessPiece {
protected:
    bool canMoveStraight; ///< Признак разрешённого прямого перемещения.
    bool canMoveDiagonal; ///< Признак разрешённого диагонального перемещения.

public:
/**
 * @brief Создаёт фигуру с заданными направлениями перемещения.
 * @param color Цвет фигуры.
 * @param x Горизонтальная координата.
 * @param y Вертикальная координата.
 * @param straight Разрешено ли прямое перемещение.
 * @param diagonal Разрешено ли диагональное перемещение.
 */
    SlidingPiece(std::string color, int x, int y,
                 bool straight, bool diagonal);

/**
 * @brief Создаёт копию фигуры с линейным перемещением.
 * @param other Копируемая фигура.
 */
    SlidingPiece(const SlidingPiece& other);

/**
 * @brief Проверяет геометрию прямого или диагонального хода.
 * @param x Целевая горизонтальная координата.
 * @param y Целевая вертикальная координата.
 * @return true, если ход соответствует разрешённому направлению и находится в пределах доски.
 * @warning Проверка не учитывает препятствия и занятые клетки.
 */
    bool canMoveTo(int x, int y) const override;
/**
 * @brief Выводит общую информацию о линейно перемещающейся фигуре.
 */
    void printInfo() const override;
};

#endif
