#pragma once
#include "Piece.h"
#include <cmath>

class Board;

class King : public Piece {
public:
    King(Color c) : Piece(c) {}

    char symbol() const override {
        return color == Color::White ? 'K' : 'k';
    }

    bool isValidMove(const Board&, int r1, int c1, int r2, int c2) const override {
        return abs(r1 - r2) <= 1 && abs(c1 - c2) <= 1;
    }
};


class Rook : public Piece {
public:
    Rook(Color c) : Piece(c) {}

    char symbol() const override {
        return color == Color::White ? 'R' : 'r';
    }

    bool isValidMove(const Board& board, int r1, int c1, int r2, int c2) const override;
};
