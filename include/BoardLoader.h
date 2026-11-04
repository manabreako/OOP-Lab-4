#ifndef BOARDLOADER_H
#define BOARDLOADER_H

#include <vector>
#include <string>
#include "ChessPiece.h"

class BoardLoader {
public:
    static std::vector<ChessPiece*> loadFromFile(
        const std::string& filename
    );
};

#endif
