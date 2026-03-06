#include <iostream>
using std::cout;
using std::cin;
using std::endl;
const int max = 10;
void changeDirection(int& currentRow, int& currentCol, int n,int& counter,int&direction,int& timesNeededToSwitchDirection,int& directionsSwitched)
{
	if (counter==timesNeededToSwitchDirection)
	{
		if (direction == 3)
		{
			direction = 0;
		}
		else
		{
			direction++;
		}
		directionsSwitched++;
		counter = 0;
		if (directionsSwitched % 2 == 0&&directionsSwitched!=0&&timesNeededToSwitchDirection<n-1)
		{
			timesNeededToSwitchDirection ++;
		}
	}
	counter++;
	switch (direction) 
	{
	case 0:
		currentCol--;
		break;
	case 1:
		currentRow--;
		break;
	case 2:
		currentCol++;
		break;
	case 3:
		currentRow++;
		break;
	}
}
void printMatrixSpirallyFromMiddle(int matrix[][max], int n)
{
	int directionsSwitched = 0;
	int timesNeededToSwitchDirection = 1;
	int direction = 0;//0-left,1-up,2-right,3-down
	int counter = 0;
	int currentRow = n / 2;
	int currentCol = n / 2;
	for (int i = 0;i < n*n;i++)
	{
		cout << matrix[currentRow][currentCol] << " ";
		changeDirection(currentRow, currentCol, n,counter,direction,timesNeededToSwitchDirection,directionsSwitched);
	}
}
void setMatrix(int matrix[][max], int n)
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
	printMatrixSpirallyFromMiddle(matrix, n);
}
