#include <iostream>
using std::cout;
using std::cin;
using std::endl;
const int MAX = 4;
void printMatrix(int matrix[][MAX])
{
    for (int i = 0;i < MAX / 2;i++)
    {
        int k = i;
        int j = MAX-1-i;
        int counter = 0;
        while (counter < 4)
        {
            if (k % 2 == 0)
            {
                cout << matrix[k][counter]<<" ";
                counter++;
            }
            else
            {
                cout << matrix[k][MAX - counter - 1]<<" ";
                counter++;
            }
        }
        counter = 0;
        while (counter < 4)
        {
            if (j % 2 == 0)
            {
                cout << matrix[j][counter]<<" ";
                counter++;
            }
            else
            {
                cout << matrix[j][MAX - counter - 1]<<" ";
                counter++;
            }
        }
    }
}
int main()
{
    int matrix[MAX][MAX];
    for (int i = 0;i < MAX;i++)
    {
        for (int j = 0;j < MAX;j++)
        {
            cin >> matrix[i][j];
        }
    }
    printMatrix(matrix);
}
