#include <iostream>
using std::cin;
using std::cout;
using std::endl;
const int MAX = 10;
void calculateOutcome(char matrix[MAX][MAX], int currentRow, int currentCol,int& previousRow,int& previousCol,int& score,bool& isGameOver)
{
    matrix[previousRow][previousCol] = '*';
    previousRow = currentRow;
    previousCol = currentCol;
    if (currentRow == 9 && currentCol == 9)
    {
        cout << "You reached the end!!!" << endl;
		isGameOver = true;
    }
    else
    {
        switch (matrix[currentRow][currentCol])
        {
        case '$':
            score++;
            break;
        case '*':
            break;
        case '#':
            isGameOver = true;
            cout << "You hit a wall. Game Over.";
            break;
        }
    }
    matrix[currentRow][currentCol] = '@';
}
bool canMoveInDirection(char direction, int currentRow, int currentCol)
{
    switch (direction)
    {
    case 'W':
        if (currentRow == 0)
            return false;
        else
            return true;
        break;
    case 'A':
        if (currentCol == 0)
            return false;
        else
            return true;
        break;
    case 'S':
        if (currentRow == MAX - 1)
            return false;
        else
            return true;
        break;
    case 'D':
        if (currentCol == MAX - 1)
            return false;
        else
            return true;
        break;
    }
}
void moveChar(char direction,int& currentRow,int& currentCol)
{
    switch (direction)
    {
    case 'W':
        if (canMoveInDirection(direction, currentRow, currentCol))
        {
            currentRow--;
        }
        else
        {
            cout << "Can't exit the field"<<endl;
        }
        break;
    case 'A':
        if (canMoveInDirection(direction, currentRow, currentCol))
        {
            currentCol--;
        }
        else
        {
            cout << "Can't exit the field"<<endl;
        }
        break;
    case 'S':
        if (canMoveInDirection(direction, currentRow, currentCol))
        {
            currentRow++;
        }
        else
        {
            cout << "Can't exit the field"<<endl;
        }
        break;
    case 'D':
        if (canMoveInDirection(direction, currentRow, currentCol))
        {
            currentCol++;
        }
        else
        {
            cout << "Can't exit the field"<<endl;
        }
        break;
    }
}
void printScore(int score)
{
    cout << "Coins: " << score<<endl;
    cout << "------------------------"<<endl;
}
void printField(char matrix[][MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0;j < MAX;j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void setDirection(char& direction)
{
    cin >> direction;
}
int main()
{
    char matrix[MAX][MAX] = {
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
	bool isGameOver = false;
    int score=0, currentRow = 0, curretnCol = 0,previousRow=0,previousCol=0;
    char direction;
    while (!isGameOver)
    {
        printField(matrix);
        printScore(score);
        setDirection(direction);
        moveChar(direction, currentRow, curretnCol);
        calculateOutcome(matrix, currentRow, curretnCol, previousRow, previousCol, score, isGameOver);
    }
}
