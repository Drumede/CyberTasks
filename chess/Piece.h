#pragma once
#include "Utils.h"

class Piece {
protected:
    Color color;

public:
    Piece(Color c) : color(c) {}
    virtual ~Piece() = default;

    Color getColor() const { return color; }
    virtual char symbol() const = 0;
    virtual bool isValidMove(const Board& board,
        int r1, int c1,
        int r2, int c2) const = 0;
};