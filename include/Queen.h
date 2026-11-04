/**
 * @file Queen.h
 * @brief Объявление класса ферзя.
 */

#ifndef QUEEN_H
#define QUEEN_H

#include "SlidingPiece.h"
#include "CombinedPiece.h"

/**
 * @class Queen
 * @brief Класс ферзя. Наследует линейное перемещение и интерфейс комбинированного хода, используя множественное наследование.
 */
class Queen : public SlidingPiece, public CombinedPiece {
public:
/**
 * @brief Создаёт ферзя.
 * @param color Цвет ферзя.
 * @param x Горизонтальная координата.
 * @param y Вертикальная координата.
 */
    Queen(std::string color, int x, int y);
/**
 * @brief Создаёт копию ферзя.
 * @param other Ферзь, данные которого копируются.
 */
    Queen(const Queen& other);

/**
 * @brief Возвращает символьное обозначение ферзя.
 * @return Символ Q.
 */
    char getSymbol() const override;

/**
 * @brief Проверяет прямое или диагональное перемещение ферзя.
 * @param x Целевая горизонтальная координата.
 * @param y Целевая вертикальная координата.
 * @return true, если геометрия хода допустима.
 */
    bool canMoveStraightOrDiagonal(int x, int y) const override;
/**
 * @brief Проверяет возможность перемещения ферзя на заданную клетку.
 * @param x Целевая горизонтальная координата.
 * @param y Целевая вертикальная координата.
 * @return true, если ход допустим; иначе false.
 */
    bool canMoveTo(int x, int y) const override;

/**
 * @brief Выводит информацию о ферзе.
 */
    void printInfo() const override;
};

#endif
