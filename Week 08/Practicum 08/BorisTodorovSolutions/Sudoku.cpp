#include <iostream>
using std::cout;
using std::cin;
using std::endl;
const int maxSize = 9;
bool isSolved(int sudoku[][maxSize])
{
	for (int i = 0;i < maxSize;i++)
	{
		for (int j = 0;j < maxSize;j++)
		{
			if (sudoku[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}
bool isValidInSquare(int sudoku[][maxSize], int row, int col, int x)
{
	int startingRow = (row/3)*3;
	int startingCol = (col/3)*3;
	for (int i = startingRow;i < startingRow + 3;i++)
	{
		for (int j = startingCol;j < startingCol + 3;j++)
		{
			if (sudoku[i][j] == x)
			{
				cout << "Element already exists in that square!"<<endl;
				return false;
			}
		}
	}
	return true;
}
bool isValidInRow(int sudoku[][maxSize], int row, int x)
{
	for (int col = 0;col < maxSize;col++)
	{
		if (sudoku[row][col] == x)
		{
			cout << "Element already exists in row - " << row<<"!"<<endl;
			return false;
		}
	}
	return true;
}
bool isValidInCol(int sudoku[][maxSize], int col,int x)
{
	for (int row = 0;row < maxSize;row++)
	{
		if (sudoku[row][col] == x)
		{
			cout << "Element already exists in column - " << col<<"!"<<endl;
			return false;
		}
	}
	return true;
}
bool isSpaceEmpty(int sudoku[][maxSize], int row, int col)
{
	if (sudoku[row][col] != 0)
	{
		cout << "That position is not empty!"<<endl;
		return false;
	}
	else
		return true;
}
bool isElementValid(int sudoku[][maxSize], int row, int col, int x)
{
	if (isSpaceEmpty(sudoku, row, col) && isValidInRow(sudoku, row, x) && isValidInCol(sudoku, col, x)&&isValidInSquare(sudoku,row,col,x))
	{
		return true;
	}
	else
	{
		return false;
	}
}
void addElement(int sudoku[][maxSize])
{
	int row, col,x;
	cout << "Enter row, column, number: ";
	cin >> row >> col >> x;
	if (isElementValid(sudoku, row, col, x))
	{
		sudoku[row][col] = x;
		cout << "Added " << x << " at position (" << row << ", " << col << ")."<< endl;
	} 
}
void printSudoku(int sudoku[][maxSize])
{
	for (int i = 0;i < maxSize; i++)
	{
		if (i % 3 == 0&& i!=0)
			cout << "------+-------+------"<<endl;
		for (int j = 0;j < maxSize;j++)
		{
			if (j % 3 == 0 && j != 0)
				cout << "| ";
			if (sudoku[i][j] == 0)
				cout << ". ";
			else
			cout << sudoku[i][j] << " ";
		}
		
		cout << endl;
	}
}
int main()
{
	int sudoku[maxSize][maxSize] = 
	{
		{0,0,9,0,0,0,0,6,0},
		{0,0,6,3,4,0,0,2,9},
		{2,3,0,5,0,0,7,0,0},
		{0,6,7,0,0,0,0,0,0},
		{0,4,0,0,3,0,0,9,0},
		{0,0,0,0,0,0,6,8,0},
		{0,0,2,0,0,1,0,3,4},
		{4,9,0,0,2,5,1,0,0},
		{0,7,0,0,0,0,8,0,0}
	};
	printSudoku(sudoku);
	while (!isSolved(sudoku))
	{
		addElement(sudoku);
		printSudoku(sudoku);
	}
	cout << "Congratulations you solved the sudoku!";
}
