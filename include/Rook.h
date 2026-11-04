/**
 * @file Rook.h
 * @brief Объявление класса ладьи.
 */

#ifndef ROOK_H
#define ROOK_H

#include "SlidingPiece.h"

/**
 * @class Rook
 * @brief Класс ладьи. Разрешает прямое перемещение по горизонтали и вертикали.
 */
class Rook : public SlidingPiece {
public:
/**
 * @brief Создаёт ладью.
 * @param color Цвет ладьи.
 * @param x Горизонтальная координата.
 * @param y Вертикальная координата.
 */
    Rook(std::string color, int x, int y);
/**
 * @brief Создаёт копию ладьи.
 * @param other Ладья, данные которой копируются.
 */
    Rook(const Rook& other);

/**
 * @brief Возвращает символьное обозначение ладьи.
 * @return Символ R.
 */
    char getSymbol() const override;
/**
 * @brief Выводит информацию о ладье.
 */
    void printInfo() const override;
};

#endif
