#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isWinner(const set<int>& playerMoves) {
    int winningCombos[8][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, 
        {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, 
        {1, 5, 9}, {3, 5, 7}             
    };
    for (auto& combo : winningCombos) {
        if (playerMoves.count(combo[0]) && playerMoves.count(combo[1]) && playerMoves.count(combo[2])) {
            return true; 
        }
    }
    return false;
}

int main() {
    vector<char> board(10, '-'); 
    set<int> player1Moves, player2Moves; 
    int currentPlayer = 1;

    while (true) {
       
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

        if (player1Moves.size() + player2Moves.size() == 9) {
            cout << "It's a draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 1 ? 2 : 1);
    }

    return 0;
}
