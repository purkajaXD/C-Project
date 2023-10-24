#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> gameBoard(3, vector<char>(3, ' '));

void displayBoard() {
    cout << "   0 1 2" << endl;
    for (int row = 0; row < 3; ++row) {
        cout << row << " ";
        for (int col = 0; col < 3; ++col) {
            cout << gameBoard[row][col] << " ";
        }
        cout << endl;
    }
}

bool checkWin(char player) {
    for (int i = 0; i < 3; ++i) {
        if ((gameBoard[i][0] == player && gameBoard[i][1] == player && gameBoard[i][2] == player) ||
            (gameBoard[0][i] == player && gameBoard[1][i] == player && gameBoard[2][i] == player)) {
            return true;
        }
    }

    if ((gameBoard[0][0] == player && gameBoard[1][1] == player && gameBoard[2][2] == player) ||
        (gameBoard[0][2] == player && gameBoard[1][1] == player && gameBoard[2][0] == player)) {
        return true;
    }

    return false;
}

bool isBoardFull() {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (gameBoard[row][col] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char currentPlayer = 'X';

    while (true) {
        displayBoard();

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && gameBoard[row][col] == ' ') {
            gameBoard[row][col] = currentPlayer;

            if (checkWin(currentPlayer)) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
                break;
            }
            else if (isBoardFull()) {
                displayBoard();
                cout << "It's a draw! The game is a tie." << endl;
                break;
            }
            else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
        else {
            cout << "Invalid move! Try again." << endl;
        }
    }

    return 0;
}