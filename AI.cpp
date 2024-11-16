#include "AI.h"
#include <limits>

Move AI::findBestMove(Board& board, int depth) {
    Move bestMove;
    int bestValue = std::numeric_limits<int>::min();

    std::vector<Move> moves = board.generateMoves();
    for (const Move& move : moves) {
        board.makeMove(move);
        int moveValue = alphaBeta(board, depth - 1, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), false);
        board.undoMove(move);
        if (moveValue > bestValue) {
            bestValue = moveValue;
            bestMove = move;
        }
    }
    return bestMove;
}

int AI::alphaBeta(Board& board, int depth, int alpha, int beta, bool maximizingPlayer) {
    if (depth == 0) {
        return board.evaluateBoard();
    }

    std::vector<Move> moves = board.generateMoves();
    if (maximizingPlayer) {
        int maxEval = std::numeric_limits<int>::min();
        for (const Move& move : moves) {
            board.makeMove(move);
            int eval = alphaBeta(board, depth - 1, alpha, beta, false);
            board.undoMove(move);
            maxEval = std::max(maxEval, eval);
            alpha = std::max(alpha, eval);
            if (beta <= alpha) {
                break;
            }
        }
        return maxEval;
    } else {
        int minEval = std::numeric_limits<int>::max();
        for (const Move& move : moves) {
            board.makeMove(move);
            int eval = alphaBeta(board, depth - 1, alpha, beta, true);
            board.undoMove(move);
            minEval = std::min(minEval, eval);
            beta = std::min(beta, eval);
            if (beta <= alpha) {
                break;
            }
        }
        return minEval;
    }
}
