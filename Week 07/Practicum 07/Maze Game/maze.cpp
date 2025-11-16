#include <iostream>
using namespace std;

const int FIELD_WIDTH = 10;
const int FIELD_HEIGHT = 10;

void printField(const char field[FIELD_WIDTH][FIELD_HEIGHT])
{
    for (int i = 0; i < FIELD_WIDTH; i++) {
        for (int j = 0; j < FIELD_HEIGHT; j++) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
}

void printInfo(const char field[FIELD_WIDTH][FIELD_HEIGHT], int coins)
{
    printField(field);
    cout << "Coins: " << coins << endl;
    cout << "--------------------------------" << endl;
}

bool isInsideField(int i, int j)
{
    return i >= 0 && j >= 0 && i < FIELD_HEIGHT && j < FIELD_WIDTH;
}

void goToPosition(char field[FIELD_WIDTH][FIELD_HEIGHT], int i, int j, int& coins, bool& gameOver)
{
    switch (field[i][j]) {
        case '$':
            coins++;
        case '*':
            field[i][j] = '@';
            break;
        case '#':
            gameOver = true;
            field[i][j] = 'X';
            return;
    }

    gameOver = (i == FIELD_HEIGHT - 1) && (j == FIELD_WIDTH - 1);
}

void moveInDirection(char field[FIELD_WIDTH][FIELD_HEIGHT],
                     int& currentHeight, int& currentWidth,
                     const char direction, int& coins, bool& gameOver)
{
    int widthCopy = currentWidth;
    int heightCopy = currentHeight;

    switch (direction) {
        case 'W':
            currentHeight--;
            break;
        case 'S':
            currentHeight++;
            break;
        case 'A':
            currentWidth--;
            break;
        case 'D':
            currentWidth++;
            break;
        default:
            cout << "Invalid direction! Try again!" << endl;
            return;
    }

    if (!isInsideField(currentHeight, currentWidth)) {
        currentWidth = widthCopy;
        currentHeight = heightCopy;
        cout << "You can't move outside the field! Try again!" << endl;
        return;
    }

    field[heightCopy][widthCopy] = '*';
    goToPosition(field, currentHeight, currentWidth, coins, gameOver);
}

void determineResult(const char field[FIELD_WIDTH][FIELD_HEIGHT])
{
    if (field[FIELD_HEIGHT - 1][FIELD_WIDTH - 1] == '@') {
        cout << "You won!" << endl;
    }
    else {
        cout << "You died! :(" << endl;
    }
}

// void clearScreen()
// {
//     cout << "\033[2J\033[1;1H";; // Doesn't work for CLion
// }

int main()
{
    char field[FIELD_HEIGHT][FIELD_WIDTH] = {
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

    bool gameOver = false;
    int coins = 0;
    int currentHeight = 0, currentWidth = 0;

    char direction;
    while (!gameOver) {
        printInfo(field, coins);

        cin >> direction;

        //clearScreen();
        moveInDirection(field, currentHeight, currentWidth, direction, coins, gameOver);
    }

    //clearScreen();
    printInfo(field, coins);
    determineResult(field);
}
