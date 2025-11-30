#include <iostream>
using std::cin;
using std::cout;
using std::endl;
const int MAX = 10;
// 1 2 3
// 0 4 5
// 0 0 6

bool checkIfMatrixIsDownTriangular(int matrix[][MAX], int n)
{
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            if (i > j && matrix[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void transpose(int matrix[][MAX], int n)
{
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            if (i < j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
}
void rotateMatrix(int matrix[][MAX], int n)
{
    transpose(matrix, n);
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n / 2;j++)
        {
            swap(matrix[i][j], matrix[i][n - j - 1]);
        }
    }
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
bool checkIfMatrixIsTriangular(int matrix[][MAX], int n)
{
    for (int i = 0;i < 4;i++)
    {
        if (checkIfMatrixIsDownTriangular(matrix,n))
        {
            return true;
        }
        else
        {
            rotateMatrix(matrix, n);
        }
    }
	return false;

}
int main()
{
    int n = 0;
    cout << "Enter size of matrix: ";
    cin >> n;
    int matrix[MAX][MAX];
    cout << "Enter matrix" << endl;
    setMatrix(matrix, n);
    if (checkIfMatrixIsTriangular(matrix,n))
    {
        cout<< "Is triangular";
    }
    else
		cout << "Is not triangular";
}
