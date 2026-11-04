/**
 * @file ChessPiece.h
 * @brief Объявление абстрактного базового класса шахматной фигуры.
 */

#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <string>
#include <iostream>

/**
 * @class ChessPiece
 * @brief Абстрактный базовый класс шахматной фигуры. Хранит цвет и координаты, предоставляет общий интерфейс и ведёт подсчёт фигур каждого цвета.
 */
class ChessPiece {
protected:
    std::string color; ///< Цвет фигуры: White или Black.
    int x; ///< Горизонтальная координата фигуры.
    int y; ///< Вертикальная координата фигуры.

    static int whiteCount; ///< Количество существующих белых фигур.
    static int blackCount; ///< Количество существующих чёрных фигур.

public:
/**
 * @brief Создаёт шахматную фигуру.
 * @param color Цвет фигуры: White или Black.
 * @param x Горизонтальная координата.
 * @param y Вертикальная координата.
 */
    ChessPiece(std::string color, int x, int y);
/**
 * @brief Создаёт копию шахматной фигуры.
 * @param other Объект, данные которого копируются.
 */
    ChessPiece(const ChessPiece& other);
/**
 * @brief Виртуальный деструктор базового класса.
 */
    virtual ~ChessPiece();

/**
 * @brief Присваивает объекту данные другой фигуры.
 * @param other Фигура-источник.
 * @return Ссылка на текущий объект.
 */
    ChessPiece& operator=(const ChessPiece& other);

/**
 * @brief Проверяет геометрическую возможность перемещения на указанную клетку.
 * @param x Целевая горизонтальная координата.
 * @param y Целевая вертикальная координата.
 * @return true, если перемещение допустимо; иначе false.
 */
    virtual bool canMoveTo(int x, int y) const = 0;
/**
 * @brief Возвращает символьное обозначение фигуры.
 * @return Символ фигуры.
 */
    virtual char getSymbol() const = 0;

/**
 * @brief Выводит общую информацию о фигуре.
 */
    virtual void printInfo() const;

/**
 * @brief Возвращает цвет фигуры.
 * @return Строка White или Black.
 */
    std::string getColor() const;
/**
 * @brief Возвращает горизонтальную координату фигуры.
 * @return Координата X.
 */
    int getX() const;
/**
 * @brief Возвращает вертикальную координату фигуры.
 * @return Координата Y.
 */
    int getY() const;

/**
 * @brief Возвращает количество существующих белых фигур.
 * @return Количество белых фигур.
 */
    static int getWhiteCount();
/**
 * @brief Возвращает количество существующих чёрных фигур.
 * @return Количество чёрных фигур.
 */
    static int getBlackCount();
/**
 * @brief Проверяет допустимость количества фигур каждого цвета.
 * @return true, если количество фигур каждого цвета находится в диапазоне от 0 до 16.
 */
    static bool validateBoardState();

/**
 * @brief Выводит краткую информацию о фигуре в поток.
 * @param out Поток вывода.
 * @param piece Фигура для вывода.
 * @return Ссылка на поток вывода.
 */
    friend std::ostream& operator<<(
        std::ostream& out, const ChessPiece& piece);
};

#endif
