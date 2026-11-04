/**
 * @file Bishop.h
 * @brief Объявление класса слона.
 */

#ifndef BISHOP_H
#define BISHOP_H

#include "SlidingPiece.h"

/**
 * @class Bishop
 * @brief Класс слона. Разрешает перемещение по диагонали в пределах шахматной доски.
 */
class Bishop : public SlidingPiece {
public:
/**
 * @brief Конструктор слона.
 * @param color Цвет фигуры: White или Black.
 * @return x Горизонтальная координата фигуры.
 * @return y Вертикальная координата фигуры.
 */
    Bishop(std::string color, int x, int y);
/**
 * @brief Конструктор копирования слона.
 * @param other Фигура, данные которой копируются.
 */
    Bishop(const Bishop& other);

/**
 * @brief Возвращает символьное обозначение слона.
 * @return Символ B.
 */
    char getSymbol() const override;
/**
 * @brief Выводит информацию о слоне.
 */
    void printInfo() const override;
};

#endif
