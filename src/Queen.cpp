/**
 * @file Queen.cpp
 * @brief Реализация методов класса ферзя.
 */

#include "Queen.h"

/**
 * @brief Создаёт ферзя с прямым и диагональным перемещением.
 * @param color Цвет фигуры.
 * @param x Горизонтальная координата.
 * @param y Вертикальная координата.
 */
Queen::Queen(std::string color, int x, int y)
    : SlidingPiece(color, x, y, true, true) {
}

/**
 * @brief Создаёт копию ферзя.
 * @param other Объект, данные которого используются для копирования.
 */
Queen::Queen(const Queen& other)
    : SlidingPiece(other) {
}

/**
 * @brief Возвращает символ Q для ферзя.
 * @return Символьное обозначение фигуры.
 */
char Queen::getSymbol() const {
    return 'Q';
}

/**
 * @brief Проверяет комбинированное прямое или диагональное перемещение.
 * @param newX Целевая горизонтальная координата.
 * @param newY Целевая вертикальная координата.
 * @return true, если геометрия хода допустима; иначе false.
 * @warning Проверка не учитывает препятствия и занятые клетки.
 */
bool Queen::canMoveStraightOrDiagonal(int x, int y) const {
    return SlidingPiece::canMoveTo(x, y);
}

/**
 * @brief Проверяет возможность хода ферзя через интерфейс комбинированного перемещения.
 * @param newX Целевая горизонтальная координата.
 * @param newY Целевая вертикальная координата.
 * @return true, если геометрия хода допустима; иначе false.
 * @warning Проверка не учитывает препятствия и занятые клетки.
 */
bool Queen::canMoveTo(int x, int y) const {
    return canMoveStraightOrDiagonal(x, y);
}

/**
 * @brief Выводит цвет, координаты и тип фигуры.
 */
void Queen::printInfo() const {
    ChessPiece::printInfo();
    std::cout << "Тип фигуры: Ферзь\n";
}
