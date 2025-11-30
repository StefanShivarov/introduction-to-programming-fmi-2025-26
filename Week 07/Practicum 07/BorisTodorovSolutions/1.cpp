#include <iostream>
using std::cin;
using std::cout;
using std::endl;
const int MAX = 10;

void printRowSums(const int matrix[][MAX], int n)
{
    for (int i = 0;i < n;i++)
    {
        int sum = 0;
        for (int j = 0;j < n;j++)
        {
            sum += matrix[i][j];
        }
        cout << "Sum of row " << i << ": " << sum << endl;
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
int main()
{
    int n = 0;
    cout << "Enter size of matrix: ";
    cin >> n;
    int matrix[MAX][MAX];
    cout << "Enter matrix" << endl;
    setMatrix(matrix, n);
    printRowSums(matrix, n);
}
