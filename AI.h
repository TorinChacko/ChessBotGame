#ifndef AI_H
#define AI_H

#include "Board.h"

class AI {
public:
    Move findBestMove(Board& board, int depth);

private:
    int alphaBeta(Board& board, int depth, int alpha, int beta, bool maximizingPlayer);
};

#endif
