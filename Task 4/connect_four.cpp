#include <iostream>
#include <vector>
using namespace std;

const int ROWS = 6;
const int COLS = 7;
const char EMPTY = '.';
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

// Function to initialize the board with empty cells
void initializeBoard(vector<vector<char>>& board) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            board[i][j] = EMPTY;
        }
    }
}

// Function to display the board
void displayBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "1 2 3 4 5 6 7" << endl;  // Column numbers for the user
}

// Function to drop a piece in a column
bool dropPiece(vector<vector<char>>& board, int col, char piece) {
    if (col < 0 || col >= COLS || board[0][col] != EMPTY) {
        return false;  // Invalid column or column full
    }
    for (int i = ROWS - 1; i >= 0; --i) {
        if (board[i][col] == EMPTY) {
            board[i][col] = piece;
            return true;
        }
    }
    return false;
}

// Function to check if there's a winning move
bool checkWin(const vector<vector<char>>& board, char piece) {
    // Check horizontal win
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS - 3; ++j) {
            if (board[i][j] == piece && board[i][j + 1] == piece &&
                board[i][j + 2] == piece && board[i][j + 3] == piece) {
                return true;
            }
        }
    }

    // Check vertical win
    for (int i = 0; i < ROWS - 3; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (board[i][j] == piece && board[i + 1][j] == piece &&
                board[i + 2][j] == piece && board[i + 3][j] == piece) {
                return true;
            }
        }
    }

    // Check diagonal win (bottom-left to top-right)
    for (int i = 3; i < ROWS; ++i) {
        for (int j = 0; j < COLS - 3; ++j) {
            if (board[i][j] == piece && board[i - 1][j + 1] == piece &&
                board[i - 2][j + 2] == piece && board[i - 3][j + 3] == piece) {
                return true;
            }
        }
    }

    // Check diagonal win (top-left to bottom-right)
    for (int i = 0; i < ROWS - 3; ++i) {
        for (int j = 0; j < COLS - 3; ++j) {
            if (board[i][j] == piece && board[i + 1][j + 1] == piece &&
                board[i + 2][j + 2] == piece && board[i + 3][j + 3] == piece) {
                return true;
            }
        }
    }

    return false;
}

// Main function to play Connect Four
int main() {
    vector<vector<char>> board(ROWS, vector<char>(COLS));
    initializeBoard(board);

    char currentPlayer = PLAYER1;
    bool gameWon = false;
    int moves = 0;

    while (!gameWon && moves < ROWS * COLS) {
        displayBoard(board);
        int col;
        cout << "Player " << (currentPlayer == PLAYER1 ? "1 (X)" : "2 (O)") << ", choose a column (1-7): ";
        cin >> col;
        col--;  // Adjust for 0-indexed board

        if (dropPiece(board, col, currentPlayer)) {
            gameWon = checkWin(board, currentPlayer);
            if (gameWon) {
                displayBoard(board);
                cout << "Player " << (currentPlayer == PLAYER1 ? "1 (X)" : "2 (O)") << " wins!" << endl;
            } else {
                currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1;  // Switch player
                moves++;
            }
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    if (!gameWon) {
        displayBoard(board);
        cout << "It's a tie!" << endl;
    }

    return 0;
}
