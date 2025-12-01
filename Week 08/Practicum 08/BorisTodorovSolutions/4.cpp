#include <iostream>
using std::cout;
using std::cin;
using std::endl;
const int max = 20;
void printSubmatricesStartingOnRow(int matrix[][max],int submatrixN, int submatrixM,int row,int m)
{
	int startingCol = 0;
	while (startingCol < m-submatrixM+1)
	{
		for (int i = row;i < submatrixN + row;i++)
		{
			for (int j = startingCol;j < startingCol + submatrixM;j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		startingCol++;
		cout << endl;
	}
}
void printSubmatrices(int matrix[][max], int n,int m)
{
	int submatrixN, submatrixM;
	cin >> submatrixN >> submatrixM;
	for (int i = 0;i < n - submatrixN + 1;i++)
	{
		printSubmatricesStartingOnRow(matrix, submatrixN, submatrixM, i,m);
	}
}
void setMatrix(int matrix[][max], int n,int m)
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
	int n, m;
	int matrix[max][max];
	cin >> n;
	cin >> m;
	setMatrix(matrix, n, m);
	printSubmatrices(matrix, n, m);
}
