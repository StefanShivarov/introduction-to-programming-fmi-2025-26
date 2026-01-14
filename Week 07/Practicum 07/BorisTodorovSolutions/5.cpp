#include <iostream>
using std::cin;
using std::cout;
using std::endl;
const int MAX = 10;
int mainDiagonalSum(const int matrix[][MAX], int n)
{
    int sum = 0;
    for (int i = 0, j = 0;i < n;i++, j++)
    {
        sum += matrix[i][j];
    }
    return sum;
}
int secondaryDiagonalSum(const int matrix[][MAX], int n)
{
    int sum = 0;
    for (int i = n - 1, j = 0;i >= 0;i--, j++)
    {
        sum += matrix[i][j];
    }
    return sum;
}
bool areRowSumsEqual(int matrix[][MAX], int n,int x)
{
    for (int i = 0;i < n;i++)
    {
        int sum = 0;
        for (int j = 0;j < n;j++)
        {
            sum += matrix[i][j];
        }
        if (sum != x)
            return false;
    }
    return true;
}
bool areColSumsEqual(int matrix[][MAX], int n,int x)
{
    for (int i = 0;i < n;i++)
    {
        int sum = 0;
        for (int j = 0;j < n;j++)
        {
            sum += matrix[j][i];
        }
        if (sum != x)
            return false;
    }
}
bool areDiagonalSumsEqual(int matrix[][MAX], int n,int x)
{
    if (mainDiagonalSum(matrix, n) != x || secondaryDiagonalSum(matrix, n) != x)
        return false;
    else
        return true;
        
}
bool isMagicSquare(int matrix[][MAX], int n)
{
    int x=0;
    //set x to be equal to first row
    for (int i = 0;i < n;i++)
    {
        x += matrix[0][i];
    }
    if (areRowSumsEqual(matrix, n,x) && areColSumsEqual(matrix, n,x) && areDiagonalSumsEqual(matrix, n,x))
        return true;
    else
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
    int n = 0;
    cout << "Enter size of matrix: ";
    cin >> n;
    int matrix[MAX][MAX];
    cout << "Enter matrix" << endl;
    setMatrix(matrix, n);
    if (isMagicSquare(matrix, n))
        cout << "magic square";
    else
        cout << "not magic square";
}
