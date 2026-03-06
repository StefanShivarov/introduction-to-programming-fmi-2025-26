#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
const int MAX = 10;
void printMatrix(int matrix[][MAX], int n)
{
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            cout <<std::setw(3)<< matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void modifyIndex(int& rowIndex, int& colIndex,int n,int& rowMax,int& colMax,int& rowMin,int& colMin,int& direction)
{
    switch (direction)
    {
    case 1://right

        if (colIndex == colMax)
        {
            direction++;
            rowMin++;//fills upmost available row
            rowIndex++;//goes down
        }
        else
            colIndex++;
        break;
    case 2://down

        if (rowIndex == rowMax)
        {
            direction++;
            colMax--;//fills rightmost available col
            colIndex--;//goes left
        }
        else
            rowIndex++;
        break;
    case 3://left
        
        if (colIndex == colMin)
        {
            direction++;
            rowMax--;//filss bottommost available row
            rowIndex--;//goes up
        }
        else 
            colIndex--;
        break;
    case 4://up
        
        if (rowIndex == rowMin)
        {
            direction = 1;
            colMin++;//fills leftmost available col
            colIndex++;//goes right
        }
        else
            rowIndex--;
        break;
    }
}
void setMatrixSpiral(int matrix[][MAX], int n)
{
    int row=0;
    int col=0;
    int rowMax = n - 1;
    int colMax = n - 1;
    int rowMin = 0;
    int colMin = 0;
    int direction = 1;//1-right,2-down,3-left,4-up
    for (int i = 1;i <= n * n;i++)
    {
        matrix[row][col]=i;
        modifyIndex(row, col, n,rowMax,colMax,rowMin,colMin,direction);
    }
}

int main()
{
    int n = 0;
    cin >> n;
    int matrix[MAX][MAX];
    setMatrixSpiral(matrix, n);
    printMatrix(matrix, n);
    
}