/**
 * @file BoardLoader.cpp
 * @brief Реализация загрузки и проверки шахматных фигур из файла.
 */

#include "BoardLoader.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"

#include <fstream>
#include <stdexcept>
#include <memory>

/**
 * @brief Загружает из файла 12 фигур, проверяет типы, цвета, координаты и минимальное количество фигур каждого типа.
 * @param filename Путь к файлу с данными фигур.
 * @return Вектор указателей на загруженные фигуры.
 * @throws std::runtime_error При ошибке открытия, чтения или проверки файла.
 */
std::vector<ChessPiece*> BoardLoader::loadFromFile(
    const std::string& filename) {

    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл!");
    }

    std::vector<ChessPiece*> pieces;

    int rookCount = 0;
    int bishopCount = 0;
    int queenCount = 0;
    int knightCount = 0;

    try {
        std::string type;
        std::string color;
        int x, y;

        while (file >> type) {

            if (!(file >> color >> x >> y)) {
                throw std::runtime_error(
                    "Ошибка формата данных в файле!"
                );
            }

            if (color != "White" && color != "Black") {
                throw std::runtime_error("Некорректный цвет фигуры!");
            }

            if (x < 0 || x > 7 || y < 0 || y > 7) {
                throw std::runtime_error("Некорректные координаты!");
            }

            std::unique_ptr<ChessPiece> piece;

            if (type == "Rook") {
                piece = std::make_unique<Rook>(color, x, y);
                rookCount++;
            }
            else if (type == "Bishop") {
                piece = std::make_unique<Bishop>(color, x, y);
                bishopCount++;
            }
            else if (type == "Queen") {
                piece = std::make_unique<Queen>(color, x, y);
                queenCount++;
            }
            else if (type == "Knight") {
                piece = std::make_unique<Knight>(color, x, y);
                knightCount++;
            }
            else {
                throw std::runtime_error("Неизвестный тип фигуры!");
            }

            pieces.push_back(piece.get());
            piece.release();
        }

        if (!file.eof()) {
            throw std::runtime_error("Ошибка чтения файла!");
        }

        if (pieces.size() != 12) {
            throw std::runtime_error(
                "В файле должно находиться 12 фигур!"
            );
        }

        if (rookCount < 3 || bishopCount < 3 ||
            queenCount < 3 || knightCount < 3) {
            throw std::runtime_error(
                "Каждого типа должно быть минимум 3 фигуры!"
            );
        }
    }
    catch (...) {
        for (ChessPiece* piece : pieces) {
            delete piece;
        }

        throw;
    }

    return pieces;
}
