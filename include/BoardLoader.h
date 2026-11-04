/**
 * @file BoardLoader.h
 * @brief Объявление загрузчика шахматных фигур из файла.
 */

#ifndef BOARDLOADER_H
#define BOARDLOADER_H

#include <vector>
#include <string>
#include "ChessPiece.h"

/**
 * @class BoardLoader
 * @brief Класс для чтения шахматных фигур из текстового файла и проверки загруженных данных.
 */
class BoardLoader {
public:
/**
 * @brief Загружает фигуры из указанного файла.
 * @param filename Путь к текстовому файлу с описанием фигур.
 * @return Вектор указателей на созданные шахматные фигуры.
 * @throws std::runtime_error Если файл не удалось открыть или данные имеют неверный формат.
 */
    static std::vector<ChessPiece*> loadFromFile(
        const std::string& filename
    );
};

#endif
