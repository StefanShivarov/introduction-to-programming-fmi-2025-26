#include <iostream>
using std::cin;
using std::cout;
using std::endl;
const int MAX = 50;
void findBigestElementInRow(int matrix[][MAX], int n, int row, int& x,int& y)
{
    y = 0;
    int currentElement = matrix[row][0];
    for (int i = 0;i < n;i++)
    {
        if (currentElement < matrix[row][i])
        {
            currentElement = matrix[row][i];
            y = i;
        }
    }
    x = row;
}
bool checkIfElementIsSmallestInCol(int matrix[][MAX], int n, int x, int y)
{
    for (int i = 0;i < n;i++)
    {
        if (matrix[x][y] > matrix[i][y])
        {
            return false;
        }
    }
    return true;
}
bool checkIfMatrixHasSaddlePoint(int matrix[][MAX], int n,int& x,int& y)
{
    for (int i = 0;i < n;i++)
    {
        findBigestElementInRow(matrix, n, i, x, y);
        if (checkIfElementIsSmallestInCol(matrix,n,x,y))
        {
            return true;
        }
    }
    return false;
}
void setMatrix(int matrix[][MAX], int n)
{
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            int x = 0;
            cin >> x;
            matrix[i][j] = x;
        }
    }
}
int main()
{
    int n = 6, x = 0, y = 0;
    int matrix[MAX][MAX];
    cout << "Enter matrix" << endl;
    setMatrix(matrix, n);
    if (checkIfMatrixHasSaddlePoint(matrix, n, x, y))
    {
        cout << "Coordinates of Saddle point:" << endl << "x: " << x << " y: " << y;
    }
    else
    {
        cout << "Matrix doesn't have Saddle point.";
    }
}