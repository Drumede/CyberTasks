#include "Pieces.h"
#include "Board.h"

bool Rook::isValidMove(const Board& board, int r1, int c1, int r2, int c2) const {
    if (r1 != r2 && c1 != c2) return false;
    return board.isPathClear(r1, c1, r2, c2);
}