#include <iostream>
using namespace std;

bool isInSubSquare(int number, int matrix[9][9], int row, int column) {
    if (row < 3)
        row = 0;
    else if (row < 6)
        row = 3;
    else
        row = 6;
    if (column < 3)
        column = 0;
    else if (column < 6)
        column = 3;
    else
        column = 6;
    for (int i = row; i < row + 3; i++)
        for (int j = column; j < column + 3; j++)
            if (matrix[i][j] == number)
                return true;
    return false;
}
bool isInRow(int number, int matrix[9][9], int row) {
    for (int i = 0; i < 9; i++)
        if (matrix[row][i] == number)
            return true;
    return false;
}
bool isInColumn(int number, int matrix[9][9], int column) {
    for (int i = 0; i < 9; i++)
        if (matrix[i][column] == number)
            return true;
    return false;
}
bool noneAreZero(int matrix[9][9]) {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (matrix[i][j] == 0)
                return false;
    return true;
}
void printMatrix(int matrix[9][9], int originalMatrix[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (matrix[i][j] == 0)
                cout << " .  ";
            else if (matrix[i][j] == originalMatrix[i][j])
                cout << "[" << matrix[i][j] << "] ";
            else
                cout << " " << matrix[i][j] << "  ";
            if (j == 2 || j == 5)
                cout << "| ";
        }
        cout << endl;
        if (i == 2 || i == 5)
            cout << "------------+-------------+------------" << endl;
    }
}
int square(int i, int j) {
    if (i < 3)
        if (j < 3)
            return 1;
        else if (j < 6)
            return 2;
        else
            return 3;
    else if (i < 6)
        if (j < 3)
            return 4;
        else if (j < 6)
            return 5;
        else
            return 6;
    else
        if (j < 3)
            return 7;
        else if (j < 6)
            return 8;
        else
            return 9;
}
int main() {
    int matrix[9][9] = {{0, 0, 9, 0, 0, 0, 0, 6, 0},
                        {0, 0, 6, 3, 4, 0, 0, 2, 9},
                        {2, 3, 0, 5, 0, 0, 7, 0, 0},
                        {0, 6, 7, 0, 0, 0, 0, 0, 0},
                        {0, 4, 0, 0, 3, 0, 0, 9, 0},
                        {0, 0, 0, 0, 0, 0, 6, 8, 0},
                        {0, 0, 2, 0, 0, 1, 0, 3, 4},
                        {4, 9, 0, 0, 2, 5, 1, 0, 0},
                        {0, 7, 0, 0, 0, 0, 8, 0, 0}};
    int originalMatrix[9][9] = {{0, 0, 9, 0, 0, 0, 0, 6, 0},
                                {0, 0, 6, 3, 4, 0, 0, 2, 9},
                                {2, 3, 0, 5, 0, 0, 7, 0, 0},
                                {0, 6, 7, 0, 0, 0, 0, 0, 0},
                                {0, 4, 0, 0, 3, 0, 0, 9, 0},
                                {0, 0, 0, 0, 0, 0, 6, 8, 0},
                                {0, 0, 2, 0, 0, 1, 0, 3, 4},
                                {4, 9, 0, 0, 2, 5, 1, 0, 0},
                                {0, 7, 0, 0, 0, 0, 8, 0, 0}};
    int row, column, number;
    while (!noneAreZero(matrix)) {
        printMatrix(matrix, originalMatrix);
        cout << "Enter row, column, number: ";
        cin >> row >> column >> number;
        if (originalMatrix[row][column] != 0)
            cout << "Invalid move! Position (" << row << ", " << column << ") is locked." << endl;
        else if (isInSubSquare(number, matrix, row, column))
            cout << "Invalid move! " << number << " is already present at subsquare " << square(row, column) << "!" << endl;
        else if (isInRow(number, matrix, row))
            cout << "Invalid move! " << number << " is already present at row " << row << "!" << endl;
        else if (isInColumn(number, matrix, column))
            cout << "Invalid move! " << number << " is already present at column " << column << "!" << endl;
        else {
            matrix[row][column] = number;
            cout << "Added " << number << " at position (" << row << ", " << column << ")" << endl;
        }
    }
    printMatrix(matrix, originalMatrix);
    cout << "Congratulations! Your have solved this Sudoku!";
}