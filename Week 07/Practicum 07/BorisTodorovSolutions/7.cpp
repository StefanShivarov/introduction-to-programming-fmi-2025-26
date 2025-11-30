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
int sumDiagonals(const int matrix[][MAX], int n)
{
    int sum = mainDiagonalSum(matrix, n) + secondaryDiagonalSum(matrix, n);
    if (n % 2 != 0)
        sum -= matrix[n / 2][n / 2];
    return sum;
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
    cout << sumDiagonals(matrix, n);
}
