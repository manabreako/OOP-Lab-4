#ifndef COMBINEDPIECE_H
#define COMBINEDPIECE_H

class CombinedPiece {
public:
    virtual bool canMoveStraightOrDiagonal(int x, int y) const = 0;
    virtual ~CombinedPiece() = default;
};

#endif
