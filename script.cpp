#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Function to check win condition
bool isWinner(const set<int>& playerMoves) {
    int winningCombos[8][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, // Rows
        {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, // Columns
        {1, 5, 9}, {3, 5, 7}             // Diagonals
    };

    // Check all winning combinations
    for (auto& combo : winningCombos) {
        if (playerMoves.count(combo[0]) && playerMoves.count(combo[1]) && playerMoves.count(combo[2])) {
            return true; // Player wins
        }
    }
    return false;
}

int main() {
    vector<char> board(10, '-'); // Board (1-9, index 0 unused)
    set<int> player1Moves, player2Moves; // Track moves for each player
    int currentPlayer = 1;

    while (true) {
        // Display board
        cout << "Board:\n";
        for (int i = 1; i <= 9; ++i) {
            cout << board[i] << (i % 3 == 0 ? "\n" : " ");
        }

        // Input move
        int move;
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (move < 1 || move > 9 || board[move] != '-') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        // Update board and track moves
        board[move] = (currentPlayer == 1 ? 'X' : 'O');
        if (currentPlayer == 1) {
            player1Moves.insert(move);
            if (isWinner(player1Moves)) {
                cout << "Player 1 wins!\n";
                break;
            }
        } else {
            player2Moves.insert(move);
            if (isWinner(player2Moves)) {
                cout << "Player 2 wins!\n";
                break;
            }
        }

        // Check for draw
        if (player1Moves.size() + player2Moves.size() == 9) {
            cout << "It's a draw!\n";
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == 1 ? 2 : 1);
    }

    return 0;
}
