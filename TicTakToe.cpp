#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

int row;
int column;
char token = 'X';
string p1;
string p2;
bool tie = false;

void displayBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}


void initializeBoard() {
    int digit;
    if (token == 'X') {
        cout << p1 << " Your move: ";
        cin >> digit;
    }
    if (token == 'O') {
        cout << p2 << " Your move: ";
        cin >> digit;
    }

    if (digit == 1) {
        row = 0;
        column = 0;
    }
    else if (digit == 2) {
        row = 0;
        column = 1;
    }
    else if (digit == 3) {
        row = 0;
        column = 2;
    }
    else if (digit == 4) {
        row = 1;
        column = 0;
    }
    else if (digit == 5) {
        row = 1;
        column = 1;
    }
    else if (digit == 6) {
        row = 1;
        column = 2;
    }
    else if (digit == 7) {
        row = 2;
        column = 0;
    }
    else if (digit == 8) {
        row = 2;
        column = 1;
    }
    else if (digit == 9) {
        row = 2;
        column = 2;
    }
    else {
        cout << "Oops, invalid response. Try again!" << endl;
        initializeBoard();
        return; // Added to prevent further execution of the function
    }

    if (board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = token;
        token = (token == 'X') ? 'O' : 'X'; // Toggle the token
    }
    else {
        cout << "This position is already filled." << endl;
        initializeBoard();
    }
}

bool winCheck() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] ||
            board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return true;
        }
    }

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] ||
        board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return true;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    tie = true;
    return false;
}

int main() {
    cout << "Enter the name of 1st Player: ";
    cin >> p1;
    cout << "Enter the name of 2nd Player: ";
    cin >> p2;

    cout << p1 << " will play first." << endl; //X belong to p1
    cout << p2 << " will play after " << p1 << endl; //O belong to p2

    displayBoard();

    while (!winCheck()) {
        initializeBoard();
        displayBoard();
    }

    if (token == 'X' && !tie) {
        cout << p2 << " Wins!" << endl;
    }
    else if (token == 'O' && !tie) {
        cout << p1 << " Wins!" << endl;
    }
    else {
        cout << "It's a Tie!" << endl;
    }

    return 0;
}