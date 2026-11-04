/**
 * @file Knight.h
 * @brief Объявление класса коня.
 */

#ifndef KNIGHT_H
#define KNIGHT_H

#include "JumpingPiece.h"

/**
 * @class Knight
 * @brief Класс коня. Наследует прыжковое перемещение и задаёт обозначение и название конкретной фигуры.
 */
class Knight : public JumpingPiece {
public:
/**
 * @brief Создаёт коня.
 * @param color Цвет коня.
 * @param x Горизонтальная координата.
 * @param y Вертикальная координата.
 */
    Knight(std::string color, int x, int y);
/**
 * @brief Создаёт копию коня.
 * @param other Конь, данные которого копируются.
 */
    Knight(const Knight& other);

/**
 * @brief Возвращает символьное обозначение коня.
 * @return Символ N.
 */
    char getSymbol() const override;
/**
 * @brief Выводит информацию о коне.
 */
    void printInfo() const override;
};

#endif

