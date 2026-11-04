/**
 * @file Bishop.cpp
 * @brief Реализация методов класса слона.
 */

#include "Bishop.h"

/**
 * @brief Создаёт слона и разрешает ему диагональное перемещение.
 * @param color Цвет фигуры.
 * @param x Горизонтальная координата.
 * @param y Вертикальная координата.
 */
Bishop::Bishop(std::string color, int x, int y)
    : SlidingPiece(color, x, y, false, true) {
}

/**
 * @brief Копирует цвет, координаты и настройки перемещения слона.
 * @param other Объект, данные которого используются для копирования.
 */
Bishop::Bishop(const Bishop& other)
    : SlidingPiece(other) {
}

/**
 * @brief Возвращает символ B для слона.
 * @return Символьное обозначение фигуры.
 */
char Bishop::getSymbol() const {
    return 'B';
}

/**
 * @brief Выводит цвет, координаты и тип фигуры.
 */
void Bishop::printInfo() const {
    ChessPiece::printInfo();
    std::cout << "Тип фигуры: Слон\n";
}
