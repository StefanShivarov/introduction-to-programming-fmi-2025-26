#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int getAverage(const int* arr, int size)
{
	int sum = 0;
	for (int i = 0;i < size;i++)
	{
		sum += arr[i];
	}
	return sum / size;
}
int getMin(const int* arr, int size)
{
	int min = arr[0];
	for (int i = 0;i < size;i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}
int getMax(const int* arr, int size)
{
	int min = arr[0];
	for (int i = 0;i < size;i++)
	{
		if (arr[i] > min)
		{
			min = arr[i];
		}
	}
	return min;
}
void setArray(int(&arr)[50], int n)
{
	for (int i = 0;i < n;i++)
	{
		int a;
		cin >> a;
		arr[i] = a;
	}
}
int findMaxMin(const int* arr, int size, int& minVal, int& maxVal)
{
	int average = getAverage(arr, size);
	minVal = getMin(arr, size);
	maxVal = getMax(arr, size);
	return average;
}
int main()
{
	const int maxOfArray = 50;
	int min=0,max=0,length = 0;
	cin >> length;
	int arr[maxOfArray];
	setArray(arr, length);
	cout << "Avg is: " << findMaxMin(arr, length, min, max) << endl;;
	cout << "Min is: " << min << ", Max is: " << max;
}

