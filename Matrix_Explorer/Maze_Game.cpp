#include <iostream>
using namespace std;

bool isValidMove(char maze[10][10], char move, int i, int j) {
    if (move == 'w') {
        if (i == 0 || maze[i - 1][j] == '#')
            return false;
    }
    else if (move == 'a') {
        if (j == 0 || maze[i][j - 1] == '#')
            return false;
    }
    else if (move == 's') {
        if (i == 9 || maze[i + 1][j] == '#')
            return false;
    }
    else if (move == 'd') {
        if (j == 9 || maze[i][j + 1] == '#')
            return false;
    }
    return true;
}
void printMaze(char maze[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            cout << maze[i][j] << " ";
        cout << endl;
    }
}
int main() {
    char maze[10][10] = {
        {'@','*','*','#','#','#','#','#','#','#'},
        {'$','#','*','#','#','#','#','#','#','#'},
        {'*','#','*','#','#','#','#','#','#','#'},
        {'*','#','*','*','#','#','#','#','#','#'},
        {'*','#','#','#','#','#','#','#','#','#'},
        {'*','*','#','#','*','*','*','*','$','#'},
        {'*','#','*','*','*','#','*','#','*','#'},
        {'*','#','*','#','#','#','*','#','#','#'},
        {'*','*','$','$','#','#','*','*','$','#'},
        {'*','#','#','#','#','#','*','$','$','*'}
    };
    char move;
    int moveI = 0, moveJ = 0;
    int coins = 0;
    printMaze(maze);
    while (maze[9][9] != '@') {
        cin >> move;
        if (move == 'w' && isValidMove(maze, 'w', moveI, moveJ)) {
            maze[moveI][moveJ] = '*';
            if (maze[moveI - 1][moveJ] == '$')
                coins++;
            maze[--moveI][moveJ] = '@';
        }
        else if (move == 'a' && isValidMove(maze, 'a', moveI, moveJ)) {
            maze[moveI][moveJ] = '*';
            if (maze[moveI][moveJ - 1] == '$')
                coins++;
            maze[moveI][--moveJ] = '@';
        }
        else if (move == 's' && isValidMove(maze, 's', moveI, moveJ)) {
            maze[moveI][moveJ] = '*';
            if (maze[moveI + 1][moveJ] == '$')
                coins++;
            maze[++moveI][moveJ] = '@';
        }
        else if (move == 'd' && isValidMove(maze, 'd', moveI, moveJ)) {
            maze[moveI][moveJ] = '*';
            if (maze[moveI][moveJ + 1] == '$')
                coins++;
            maze[moveI][++moveJ] = '@';
        }
        else {
            cout << "Game Over!" << endl;
            return 0;
        }
        printMaze(maze);
        cout << "Coins: " << coins << endl;
        cout << "--------------------------------" << endl;
    }
    cout << "Win!";
}