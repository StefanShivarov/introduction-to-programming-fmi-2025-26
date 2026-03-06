#include <iostream>
using std::cin;
using std::cout;
using std::endl;
const int MAX = 10;
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
bool isMatrixSymmetrical(int matrix[][MAX], int n)
{
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int n = 0;
    cout << "Enter size of matrix: ";
    cin >> n;
    int matrix[MAX][MAX];
    cout << "Enter matrix" << endl;
    setMatrix(matrix, n);
    if (isMatrixSymmetrical(matrix, n))
        cout << "Is symmetrical";
    else
        cout << "Is not symmetrical";
}
