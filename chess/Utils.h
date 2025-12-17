#pragma once

// ================= Enums =================

enum class Color { White, Black };

enum class MoveResult {
    OK = '0',
    InvalidFormat = '1',
    NoPiece = '2',
    NotYourTurn = '3',
    IllegalMove = '4'
};

// ================= Helpers =================

int fileToCol(char f);
int rankToRow(char r);

class Board; // forward declaration
