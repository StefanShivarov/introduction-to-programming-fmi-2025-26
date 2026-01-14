#include <iostream>
using std::cin;
using std::cout;
using std::endl;
const int MAX = 50;
void transformArrayIntoMatrix(int arr[], int size, int matrix[][MAX], int n, int m)
{
    int counter = 0;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            matrix[i][j] = arr[counter];
            counter++;
        }
    }
}
void sortArray(int arr[], int size)
{
    for (int i = 0;i < size - 1;i++)
    {
        for (int j = 0;j < size - i - 1;j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void transformMatrixIntoArray(int matrix[][MAX], int n, int m, int arr[])
{
	int counter = 0;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            arr[counter] = matrix[i][j];
			counter++;
        }
	}
}
void printMatrix(int matrix[][MAX], int n,int m)
{
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            cout  << matrix[i][j] << " ";
        }
        cout << endl;
    }
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
	int arr[MAX * MAX];
    cout << "Enter matrix" << endl;
    setMatrix(matrix, n, m);
	transformMatrixIntoArray(matrix, n, m, arr);
	sortArray(arr, n * m);
	transformArrayIntoMatrix(arr, n * m, matrix, n, m);
	printMatrix(matrix, n, m);
}
