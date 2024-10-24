#include <iostream>
using namespace std;

// Size of the Tic Tac Toe board
const int SIZE = 3;

// Function to print how to board looks
void printTICTACTOEBoard(const char board[SIZE][SIZE]) {
    cout << "  0 1 2\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << " ";
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

// Function to check if there is a win on the board
bool isWinner(const char board[SIZE][SIZE], char player) {
    // Check rows and columns for a win
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check both diagonals for a win
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the board is fully occupied without any wins
bool isDraw(const char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

// Main game loop
void gameLoop() {
    char board[SIZE][SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    bool player1Turn = true;
    while (true) {
        printTICTACTOEBoard(board);
        int row, col;
        cout << "Player " << (player1Turn ? "1 (X)" : "2 (O)") << ", enter your move (row and column): ";
        cin >> row >> col;
        // Validate the chosen position
        while (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            cout << "Invalid move. Please try again: ";
            cin >> row >> col;
        }
        // Set the player's symbol
        board[row][col] = player1Turn ? 'X' : 'O';
        if (isWinner(board, player1Turn ? 'X' : 'O')) {
            printTICTACTOEBoard(board);
            cout << "Player " << (player1Turn ? "1" : "2") << " wins!\n";
            break;
        }
        if (isDraw(board)) {
            printTICTACTOEBoard(board);
            cout << "The game is a draw.\n";
            break;
        }
        player1Turn = !player1Turn;
    }
}

// Main function to run the game with a menu
int main() {
    char option;
    do {
        cout << "Tic Tac Toe Game\n";
        cout << "1. Start new game\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;
        switch (option) {
            case '1':
                gameLoop();
                break;
            case '2':
                cout << "Exiting game.\n";
                return 0;
            default:
                cout << "Invalid option. Please enter 1 or 2.\n";
        }
    } while (option != '2');
}
