#include <iostream>
using std::cin;
using std::cout;
using std::endl;
const int MAX = 10;
void printMatrix(int matrix[][MAX], int n, int m)
{
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int calculateElement(const int matrix1[][MAX], int rowIndex, int m, const int matrix2[][MAX], int p, int colIndex)
{
    int x = 0;
    for (int i = 0,j=0;i < m;i++,j++)
    {
        x += matrix1[rowIndex][i] * matrix2[j][colIndex];
    }
    return x;
}
void multiplyMatrix(const int matrix1[][MAX], int n, int m, const int matrix2[][MAX], int p, int q, int matrixReult[][MAX])
{
    if (m != p)
    {
        cout << "Matrix multiplication is not possible";
        return;
    }
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < q;j++)
        {
            matrixReult[i][j] = calculateElement(matrix1, i, m, matrix2, p, j);
        }
    }
    printMatrix(matrixReult, n, q);
}

void setMatrix(int matrix[][MAX], int n,int m)
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
    int n,m,p,q;
    int matrix1[MAX][MAX],matrix2[MAX][MAX],matrixResult[MAX][MAX];
    cout << "N: ";
    cin >> n;
    cout << "M: ";
    cin >> m;
    cout << "Enter matrix1" << endl;
    setMatrix(matrix1, n,m);
    cout << "P: ";
    cin >> p;
    cout << "Q: ";
    cin >> q;
    cout << "Enter matrix2" << endl;
    setMatrix(matrix2, p,q);
    multiplyMatrix(matrix1, n, m, matrix2, p, q, matrixResult);
}
