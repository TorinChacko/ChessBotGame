#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Move.h"

enum Piece { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING };
enum Player { WHITE, BLACK };

class Board {
public:
    Board();
    void initializeBoard();
    void printBoard() const;
    std::vector<Move> generateMoves() const;
    void makeMove(const Move& move);
    void undoMove(const Move& move);
    bool isCheckmate() const;
    bool isStalemate() const;
    int evaluateBoard() const;
    Player getCurrentPlayer() const;

private:
    Piece board[8][8];
    Player currentPlayer;
    // Additional helper functions and member variables
};

#endif
