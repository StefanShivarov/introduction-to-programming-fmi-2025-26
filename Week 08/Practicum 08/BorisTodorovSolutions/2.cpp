#include <iostream>
using std::cout;
using std::cin;
using std::endl;
const int max = 50;
void printOuterLayerClockwise(int matrix[][max], int& n)
{
	int matrixWithoutOuterLayer[max][max];
	int sizeOfNewMatrix=0;
	for (int i = 0,i2=1;i2 < n-1;i++,i2++)
	{
		for (int j = 0,j2=1;j2 < n-1;j++,j2++)
		{
			matrixWithoutOuterLayer[i][j] = matrix[i2][j2];
			sizeOfNewMatrix = n - 2;
		}
	}
	for (int i = 0;i < n;i++)
	{
		cout << matrix[0][i] << " ";//prints first row left-right
	}
	for (int i = 1;i < n;i++)
	{
		cout << matrix[i][n - 1] << " ";//prints last col top-down
	}
	for (int i = 1;i < n;i++)
	{
		cout << matrix[n - 1][n - 1 - i] << " ";//prints last row right-left
	}
	for (int i = 1;i < n-1;i++)
	{
		cout << matrix[n-1-i][0] << " ";//prints first col down-top
	}
	for (int i = 0;i < sizeOfNewMatrix;i++)
	{
		for (int j = 0;j < sizeOfNewMatrix;j++)
		{
			matrix[i][j] = matrixWithoutOuterLayer[i][j];
		}
	}
	n = sizeOfNewMatrix;
}
void printOuterLayerCounterClockwise(int matrix[][max], int& n)
{
	int matrixWithoutOuterLayer[max][max];
	int sizeOfNewMatrix = 0;
	for (int i = 0, i2 = 1;i2 < n - 1;i++,i2++)
	{
		for (int j = 0, j2 = 1;j2 < n - 1;j++,j2++)
		{
			matrixWithoutOuterLayer[i][j] = matrix[i2][j2];
			sizeOfNewMatrix = n - 2;
		}
	}
	for (int i = 0;i < n;i++)
	{
		cout << matrix[0][n-i-1]<<" ";//prints first row right-left
	}
	for (int i = 1;i < n;i++)
	{
		cout << matrix[i][0] << " ";//prints first col top-down
	}
	for (int i = 1;i < n;i++)
	{
		cout << matrix[n - 1][i] << " ";//prints last row left-right
	}
	for (int i = 1;i < n-1;i++)
	{
		cout << matrix[n-1-i][n - 1] << " ";//prints last col down-top
	}
	for (int i = 0;i < sizeOfNewMatrix;i++)
	{
		for (int j = 0;j < sizeOfNewMatrix;j++)
		{
			matrix[i][j] = matrixWithoutOuterLayer[i][j];
		}
	}
	n = sizeOfNewMatrix;
}
void setMatrix(int matrix[][max],int n)
{
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cin >> matrix[i][j];
		}
	}
}
int main()
{
	int matrix[max][max];
	int n;
	cin >> n;
	setMatrix(matrix, n);
	int nPerm = n;
	int middleElement = 0;
	if (n % 2 != 0)
	{
		middleElement = matrix[n / 2][n / 2];
	}
	for (int i = 0;i < nPerm/2;i++)
	{
		if (i % 2 == 0)
			printOuterLayerClockwise(matrix, n);
		else
			printOuterLayerCounterClockwise(matrix, n);
	}
	if (n % 2 != 0)
	{
		cout << middleElement;
	}
}
