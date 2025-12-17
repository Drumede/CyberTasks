#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <cmath>
#include "Pieces.h"

using namespace std;

class Piece;
class King;
class Rook;

class Board {
private:
    vector<vector<unique_ptr<Piece>>> grid;

public:
    Board() {
        grid.resize(8);
        for (int r = 0; r < 8; ++r)
            grid[r].resize(8);

        grid[0][0] = unique_ptr<Piece>(new Rook(Color::Black));
        grid[0][4] = unique_ptr<Piece>(new King(Color::Black));
        grid[7][0] = unique_ptr<Piece>(new Rook(Color::White));
        grid[7][4] = unique_ptr<Piece>(new King(Color::White));
    }

    Piece* at(int r, int c) const {
        return grid[r][c].get();
    }

    bool isPathClear(int r1, int c1, int r2, int c2) const {
        int dr = (r2 > r1) - (r2 < r1);
        int dc = (c2 > c1) - (c2 < c1);
        r1 += dr;
        c1 += dc;
        while (r1 != r2 || c1 != c2) {
            if (grid[r1][c1]) return false;
            r1 += dr;
            c1 += dc;
        }
        return true;
    }

    void movePiece(int r1, int c1, int r2, int c2) {
        grid[r2][c2] = move(grid[r1][c1]);
    }

    void print() const {
        cout << "\n  a b c d e f g h\n";
        for (int r = 0; r < 8; ++r) {
            cout << 8 - r << " ";
            for (int c = 0; c < 8; ++c) {
                if (grid[r][c]) cout << grid[r][c]->symbol();
                else cout << '.';
                cout << ' ';
            }
            cout << 8 - r << '\n';
        }
        cout << "  a b c d e f g h\n" << endl;
    }

    pair<int, int> findKing(Color color) const {
        for (int r = 0; r < 8; ++r)
            for (int c = 0; c < 8; ++c)
                if (grid[r][c] &&
                    grid[r][c]->getColor() == color &&
                    tolower(grid[r][c]->symbol()) == 'k')
                    return { r, c };
        return { -1, -1 };
    }

    bool isKingInCheck(Color kingColor) const {
        pair<int, int> kingPos = findKing(kingColor);
        int kr = kingPos.first;
        int kc = kingPos.second;

        if (kr == -1) return false;

        for (int r = 0; r < 8; ++r) {
            for (int c = 0; c < 8; ++c) {
                if (!grid[r][c]) continue;
                if (grid[r][c]->getColor() == kingColor) continue;

                if (grid[r][c]->isValidMove(*this, r, c, kr, kc))
                    return true;
            }
        }
        return false;
    }


    bool wouldCauseCheck(int r1, int c1, int r2, int c2, Color mover) {
        auto captured = move(grid[r2][c2]);
        grid[r2][c2] = move(grid[r1][c1]);

        bool inCheck = isKingInCheck(mover);

        grid[r1][c1] = move(grid[r2][c2]);
        grid[r2][c2] = move(captured);

        return inCheck;
    }

};
