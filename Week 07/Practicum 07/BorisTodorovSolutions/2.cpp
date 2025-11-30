#include <iostream>
using std::cin;
using std::cout;
using std::endl;
const int MAX = 10;

void countNegativeNumInRow(const int matrix[][MAX], int n)
{

    for (int i = 0;i < n;i++)
    {
        int count = 0;
        for (int j = 0;j < n;j++)
        {
            if (matrix[i][j] < 0)
                count++;
        }
        cout << "Count of negatives in row " << i << ": " << count << endl;
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
    countNegativeNumInRow(matrix, n);
}
