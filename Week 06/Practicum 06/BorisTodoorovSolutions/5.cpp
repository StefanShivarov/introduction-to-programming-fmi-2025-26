#include <iostream>
using std::cin;
using std::cout;
using std::endl;
void swap(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}
void printArray(double(&arr)[50], int length)
{
	for (int i = 0;i < length;i++)
	{
		cout << arr[i] << " ";
	}
}
void sortArray(double(&arr)[50], int length)
{
	for (int i = 0;i < length;i++)
	{
		int minIndex = i;
		for (int j = i+1;j < length;j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		if (i != minIndex)
		{
			swap(arr[i], arr[minIndex]);
		}
	}
}
void setArray(double(&arr)[50], int n)
{
	for (int i = 0;i < n;i++)
	{
		double a;
		cin >> a;
		arr[i] = a;
	}
}
int main()
{
	const int maxOfArray = 50;
	int length = 0;
	cin >> length;
	double arr[maxOfArray];
	setArray(arr, length);
	sortArray(arr, length);
	printArray(arr, length);
}

