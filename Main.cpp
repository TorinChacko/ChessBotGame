#include <iostream>
#include "Board.h"
#include "AI.h"

using namespace std;

void playGame() {
    Board board;
    AI ai;
    board.initializeBoard();

    while (true) {
        board.printBoard();

        if (board.getCurrentPlayer() == WHITE) {
            cout << "Enter your move (format: fromX fromY toX toY): ";
            Move playerMove;
            cin >> playerMove.fromX >> playerMove.fromY >> playerMove.toX >> playerMove.toY;
            board.makeMove(playerMove);
        } else {
            cout << "AI is thinking..." << endl;
            Move aiMove = ai.findBestMove(board, 3); // Depth of 3 for alpha-beta pruning
            board.makeMove(aiMove);
            cout << "AI moves from (" << aiMove.fromX << ", " << aiMove.fromY << ") to (" << aiMove.toX << ", " << aiMove.toY << ")" << endl;
        }

        if (board.isCheckmate()) {
            cout << "Checkmate!" << endl;
            break;
        }
        if (board.isStalemate()) {
            cout << "Stalemate!" << endl;
            break;
        }
    }
}

int main() {
    playGame();
    return 0;
}
