
#include "Pieces.h"
#include "Board.h"

// ================= Board =================




// ================= Game =================

class Game {
private:
    Board board;
    Color turn = Color::White;

public:
    MoveResult handleMove(const string& cmd) {
        if (cmd.size() != 4)
            return MoveResult::InvalidFormat;

        int c1 = fileToCol(cmd[0]);
        int r1 = rankToRow(cmd[1]);
        int c2 = fileToCol(cmd[2]);
        int r2 = rankToRow(cmd[3]);

        if (r1 < 0 || r1 > 7 || r2 < 0 || r2 > 7 ||
            c1 < 0 || c1 > 7 || c2 < 0 || c2 > 7)
        {
            board.print();
            return MoveResult::InvalidFormat;
        }

        Piece* p = board.at(r1, c1);
        if (!p) 
        {
            board.print();
            return MoveResult::NoPiece;
        }
        if (p->getColor() != turn) 
        {
            board.print();
            return MoveResult::NotYourTurn;
        }

        Piece* dst = board.at(r2, c2);
        if (dst && dst->getColor() == turn) {
            board.print();
            return MoveResult::IllegalMove;
        }

        if (!p->isValidMove(board, r1, c1, r2, c2))
        {
            board.print();
            return MoveResult::IllegalMove;
        }

        if (board.wouldCauseCheck(r1, c1, r2, c2, turn)) {
            board.print();
            return MoveResult::IllegalMove;
        }

        board.movePiece(r1, c1, r2, c2);
        Color enemy = (turn == Color::White) ? Color::Black : Color::White;
        if (board.isKingInCheck(enemy))
            cout << "CHECK!" << endl;
        turn = (turn == Color::White) ? Color::Black : Color::White;

        cout << "Move " << cmd << " executed successfully" << endl;
        board.print();

        return MoveResult::OK;
    }
};

// ================= main =================

int main() {
    Game game;
    string move;

    game.handleMove("a1a1");

    while (cin >> move) {
        if (move == "quit") break;
        MoveResult res = game.handleMove(move);
        cout << char(res) << endl;
    }
    return 0;
}
