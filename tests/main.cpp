#include <iostream>
#include <vector>
#include <clocale>
#ifdef _WIN32
#include <windows.h>
#endif
#include "BoardLoader.h"
#include "Rook.h"

using namespace std;

int main() {
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif

    setlocale(LC_ALL, ".UTF8");

    vector<ChessPiece*> board;

    try {
        // Загружаем фигуры из файла
        board = BoardLoader::loadFromFile("tests/pieces.txt");

        cout << "=== Шахматные фигуры ===\n\n";

        // Проверка полиморфизма
        for (ChessPiece* piece : board) {
            piece->printInfo();

            cout << "Символ: " << piece->getSymbol() << endl;

            cout << "Можно ли переместиться на (5, 5): "
                 << (piece->canMoveTo(5, 5) ? "Да" : "Нет")
                 << "\n\n";
        }

        // Проверка конструктора копирования
        Rook* firstRook = dynamic_cast<Rook*>(board[0]);

        if (firstRook == nullptr) {
            throw runtime_error("Не удалось получить ладью!");
        }

        Rook rookCopy(*firstRook);

        cout << "=== Конструктор копирования ===\n";
        cout << "Копия: " << rookCopy << endl;

        // Проверка оператора присваивания
        Rook anotherRook("Black", 7, 7);
        anotherRook = *firstRook;

        cout << "\n=== Оператор присваивания ===\n";
        cout << "Присвоенная фигура: "
             << anotherRook << endl;

        // Проверка статических счётчиков
        cout << "\n=== Количество фигур ===\n";

        cout << "Белых фигур: "
             << ChessPiece::getWhiteCount() << endl;

        cout << "Чёрных фигур: "
             << ChessPiece::getBlackCount() << endl;

        cout << "Состояние доски: "
             << (ChessPiece::validateBoardState()
                 ? "Корректное" : "Некорректное")
             << endl;

        // Проверка независимости копии
        rookCopy = Rook("White", 5, 5);

        cout << "\n=== Проверка независимости копии ===\n";
        cout << "Оригинал: " << *firstRook << endl;
        cout << "Копия: " << rookCopy << endl;
    }
    catch (const exception& error) {
        cout << "Ошибка: " << error.what() << endl;
    }

    // Проверка обработки исключений
    cout << "\n=== Проверка обработки исключений ===\n";

    try {
        BoardLoader::loadFromFile("tests/missing.txt");
    }
    catch (const exception& error) {
        cout << "Исключение успешно обработано: "
            << error.what() << endl;
    }

    // Освобождение памяти
    for (ChessPiece* piece : board) {
        delete piece;
    }

    return 0;
}
