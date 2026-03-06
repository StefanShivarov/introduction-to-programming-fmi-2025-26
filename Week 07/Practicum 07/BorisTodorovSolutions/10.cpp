#include <iostream>
using std::cin;
using std::cout;
using std::endl;
const int MAX = 50;
bool areDiagonalsIncreasing(int matrix[][MAX], int n, int m)
{
    for (int i = 0;i < n;i++)
    {
        int element = matrix[i][0];
        for (int j = 1;j < i+1;j++)
        {
            if (matrix[i-j][j] < element)
                return false;
            else
                element = matrix[i-j][j];
        }
    }
    for (int i = 1;i < m;i++)
    {
        int element = matrix[n-1][i];
        for (int j = 1; n - 1 - j >= 0 && i + j < m ;j++)
        {
            if (matrix[n- 1- j][i+j] < element)
                return false;
            else
                element = matrix[n - 1 - j][i+j];
        }
    }
    return true;
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
    setMatrix(matrix, n,m);
    if (areDiagonalsIncreasing(matrix,n,m))
        cout << "true";
    else
        cout << "false";
}
