#include <iostream>
using std::cout;
using std::cin;
using std::endl;
const int MAX = 20;
void swap(int& n, int& m)
{
	n = m + n;
	m = n - m;
	n = n - m;
}
void printMatrix(int matrix[][MAX], int n, int m)
{
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cout << matrix[i][j]<<" ";
		}
		cout << endl;
	}
}
void rotateMatrix(int matrix[][MAX], int& n, int& m)
{
	int tempMatrix[MAX][MAX];
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
		{
			tempMatrix[i][j] = matrix[n-j-1][i];
		}
	}
	swap(n, m);
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			matrix[i][j] = tempMatrix[i][j];
		}
	}
}
int transformDegreesIntoRotationsToTheRight(int degrees)
{
	int rotations = degrees / 90;
	rotations = rotations % 4;
	if (rotations < 0)
	{
		rotations = 4 + rotations;
	}
	return rotations;
}
void printRotatedMatrix(int matrix[][MAX], int& n, int& m,int degrees)
{
	int timesToRotateToTheRight = transformDegreesIntoRotationsToTheRight(degrees);
	for (int i = 0;i < timesToRotateToTheRight;i++)
	{
		rotateMatrix(matrix, n, m);
	}
	printMatrix(matrix, n, m);
}
void setMatrix(int matrix[][MAX], int n, int m)
{
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cin >> matrix[i][j];
		}
	}
}
int main()
{
	int n, m,degrees;
	int matrix[MAX][MAX];
	cin >> n>>m;
	setMatrix(matrix, n, m);
	cin >> degrees;
	printRotatedMatrix(matrix,n,m,degrees);
}