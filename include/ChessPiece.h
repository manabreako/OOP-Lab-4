#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <string>
#include <iostream>

class ChessPiece {
protected:
    std::string color;
    int x;
    int y;

    static int whiteCount;
    static int blackCount;

public:
    ChessPiece(std::string color, int x, int y);
    ChessPiece(const ChessPiece& other);
    virtual ~ChessPiece();

    ChessPiece& operator=(const ChessPiece& other);

    virtual bool canMoveTo(int x, int y) const = 0;
    virtual char getSymbol() const = 0;

    virtual void printInfo() const;

    std::string getColor() const;
    int getX() const;
    int getY() const;

    static int getWhiteCount();
    static int getBlackCount();
    static bool validateBoardState();

    friend std::ostream& operator<<(
        std::ostream& out, const ChessPiece& piece);
};

#endif
