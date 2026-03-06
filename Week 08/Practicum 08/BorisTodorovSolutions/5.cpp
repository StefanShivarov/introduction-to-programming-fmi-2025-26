#include <iostream>
using std::cout;
using std::cin;
using std::endl;
const int MAX = 20;
int findMaxSumOfSubmatricesOnRow(int matrix[][MAX], int submatrixN, int submatrixM, int row, int m)
{
	int currentSum = 0;
	int maxSumOnRow = INT_MIN;
	int startingCol = 0;
	while (startingCol < m - submatrixM + 1)
	{
		for (int i = row;i < submatrixN + row;i++)
		{
			for (int j = startingCol;j < startingCol + submatrixM;j++)
			{
				currentSum += matrix[i][j];
			}
		}
		if (currentSum > maxSumOnRow)
			maxSumOnRow = currentSum;
		currentSum = 0;
		startingCol++;
	}
	return maxSumOnRow;
}
int findSubmatricesMaxSum(int matrix[][MAX], int n, int m)
{
	int maxSum = INT_MIN;
	int submatrixN, submatrixM;
	cin >> submatrixN >> submatrixM;
	for (int i = 0;i < n - submatrixN + 1;i++)
	{
		int currentSum = findMaxSumOfSubmatricesOnRow(matrix,submatrixN,submatrixM,i,m);
		if (currentSum > maxSum)
				maxSum = currentSum;
	}
	return maxSum;
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
	int n, m;
	int matrix[MAX][MAX];
	cin >> n;
	cin >> m;
	setMatrix(matrix, n, m);
	cout << findSubmatricesMaxSum(matrix, n, m);
}
