#include <iostream>
using std::cin;
using std::cout;
using std::endl;
const int MAX = 50;
void modifyIndex(int& rowIndex, int& colIndex, int n, int& rowMax, int& colMax, int& rowMin, int& colMin, int& direction)
{
    switch (direction)
    {
    case 1://right

        if (colIndex == colMax)
        {
            direction=4;
            rowMax--;//fills bottommost available row
            rowIndex--;//go up
        }
        else
            colIndex++;
        break;
    case 2://down

        if (rowIndex == rowMax)
        {
            direction--;
            colMin++;//fills leftmost available col
            colIndex++;//go right
        }
        else
            rowIndex++;
        break;
    case 3://left

        if (colIndex == colMin)
        {
            direction--;
            rowMin++;//fills upmost available row
            rowIndex++;//go down
        }
        else
            colIndex--;
        break;
    case 4://up

        if (rowIndex == rowMin)
        {
            direction --;
            colMax--;//fils rightmost available col
            colIndex--;//go left
        }
        else
            rowIndex--;
        break;
    }
}
void printMatrixSpiral(int matrix[][MAX], int n,int m)
{
    int row = n-1;
    int col = m-1;
    int rowMax = n - 1;
    int colMax = m - 1;
    int rowMin = 0;
    int colMin = 0;
    int direction = 4;//1-right,2-down,3-left,4-up
    for (int i = 0;i < n * m;i++)
    {
        cout << matrix[row][col]<<" ";
        modifyIndex(row, col, n, rowMax, colMax, rowMin, colMin, direction);
    }
}
void setMatrix(int matrix[][MAX], int n, int m)
{
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            int x = 0;
            cin >> x;
            matrix[i][j] = x;
        }
    }
}
int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;
    int matrix[MAX][MAX];
    cout << "Enter matrix" << endl;
    setMatrix(matrix, n, m);
    printMatrixSpiral(matrix, n, m);
}
