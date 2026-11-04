/**
 * @file CombinedPiece.h
 * @brief Объявление интерфейса комбинированного перемещения.
 */

#ifndef COMBINEDPIECE_H
#define COMBINEDPIECE_H

/**
 * @class CombinedPiece
 * @brief Абстрактный интерфейс для фигур, поддерживающих комбинированное прямое и диагональное перемещение.
 */
class CombinedPiece {
public:
/**
 * @brief Проверяет возможность прямого или диагонального перемещения.
 * @param x Целевая горизонтальная координата.
 * @param y Целевая вертикальная координата.
 * @return true, если перемещение допустимо; иначе false.
 */
    virtual bool canMoveStraightOrDiagonal(int x, int y) const = 0;
/**
 * @brief Виртуальный деструктор интерфейса.
 */
    virtual ~CombinedPiece() = default;
};

#endif
