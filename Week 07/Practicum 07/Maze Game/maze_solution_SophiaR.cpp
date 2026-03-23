#include <iostream>
using std::cin;
using std::cout;
using std::endl;

bool validMove(char matrix[10][10], char move, int moveI, int moveJ) {
    if (move == 'w') {
        if (moveI > 0 && (matrix[moveI - 1][moveJ] != '#')) {
            return true;
        }
    }
    else if (move == 's') {
        if (moveI < 9 && (matrix[moveI + 1][moveJ] != '#')) {
            return true;
        }
    }
    else if (move == 'a') {
        if (moveJ > 0 && (matrix[moveI][moveJ - 1] != '#')) {
            return true;
        }
    }
    else if (move == 'd') {
        if (moveJ < 9 && (matrix[moveI][moveJ + 1] != '#')) {
            return true;
        }
    }
    return false;

}

void moveUp(char matrix[10][10], int& moveI, int& moveJ, int& sumDollar) {
    if (validMove(matrix, 'w', moveI, moveJ) == true) {
        if (matrix[moveI - 1][moveJ] == '$') {
            sumDollar++;
        }
        matrix[moveI][moveJ] = '*';
        matrix[moveI - 1][moveJ] = '@';
        moveI -= 1;
    }
}

void moveDown(char matrix[10][10], int& moveI, int& moveJ, int& sumDollar) {
    if (validMove(matrix, 's', moveI, moveJ) == true) {
        if (matrix[moveI + 1][moveJ] == '$') {
            sumDollar++;
        }
        matrix[moveI][moveJ] = '*';
        matrix[moveI + 1][moveJ] = '@';
        moveI += 1;
    }
}

void moveLeft(char matrix[10][10], int& moveI, int& moveJ, int& sumDollar) {
    if (validMove(matrix, 'a', moveI, moveJ) == true) {
        if (matrix[moveI][moveJ - 1] == '$') {
            sumDollar++;
        }
        matrix[moveI][moveJ] = '*';
        matrix[moveI][moveJ - 1] = '@';
        moveJ -= 1;
    }
}

void moveRight(char matrix[10][10], int& moveI, int& moveJ, int& sumDollar) {
    if ((validMove(matrix, 'd', moveI, moveJ) == true)) {
        if (matrix[moveI][moveJ + 1] == '$') {
            sumDollar++;
        }
        matrix[moveI][moveJ] = '*';
        matrix[moveI][moveJ + 1] = '@';
        moveJ += 1;
    }
}


void printLabirinth(char matrix[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    char labirinthMatrix[10][10]{
        {'@', '*', '*', '#', '#', '#', '#', '#', '#', '#'},
        {'$', '#', '*', '#', '#', '#', '#', '#', '#', '#'},
        {'*', '#', '*', '#', '#', '#', '#', '#', '#', '#'},
        {'*', '#', '*', '*', '#', '#', '#', '#', '#', '#'},
        {'*', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'*', '*', '#', '#', '*', '*', '*', '*', '$', '#'},
        {'*', '#', '*', '*', '*', '#', '*', '#', '*', '#'},
        {'*', '#', '*', '#', '#', '#', '*', '#', '#', '#'},
        {'*', '*', '$', '$', '#', '#', '*', '*', '$', '#'},
        {'*', '#', '#', '#', '#', '#', '*', '$', '$', '*'}
    };

    char move;
    int moveI = 0;
    int moveJ = 0;
    int sumDollar = 0;
    printLabirinth(labirinthMatrix);
    cout << endl;
    cout << "Enter a move : " << endl;
    cout << "w is for up " << endl;
    cout << "s is for down " << endl;
    cout << "a is for left " << endl;
    cout << "d is for right " << endl;
    cout << endl;

    while (labirinthMatrix[9][9] != '@') {
        cin >> move;
        if (validMove(labirinthMatrix, move, moveI, moveJ) == false) {
            cout << "GAME OVER" << endl;
            break;
        }
        else if (validMove(labirinthMatrix, move, moveI, moveJ) == true) {
            if (move == 'w') {
                moveUp(labirinthMatrix, moveI, moveJ, sumDollar);
                printLabirinth(labirinthMatrix);
            }
            else if (move == 's') {
                moveDown(labirinthMatrix, moveI, moveJ, sumDollar);
                printLabirinth(labirinthMatrix);
            }
            else if (move == 'a') {
                moveLeft(labirinthMatrix, moveI, moveJ, sumDollar);
                printLabirinth(labirinthMatrix);
            }
            else if (move == 'd') {
                moveRight(labirinthMatrix, moveI, moveJ, sumDollar);
                printLabirinth(labirinthMatrix);
            }
            cout << "Dollars: " << sumDollar << endl;
            cout << "-----------------------" << endl;
            cout << endl;
        }
    }
    if (labirinthMatrix[9][9] == '@') {
        cout << "YOU WIN!" << endl;
    }
    return 0;
}
