#include <iostream>
using std::cin;
using std::cout;
using std::endl;
void mergeArrays(int(&newArr)[50], int(&firstArr)[25], int firstLength, int(&secondArr)[25], int secondLength)
{
	for (int i = 0;i < firstLength;i++)
	{
		newArr[i] = firstArr[i];
	}
	for (int i = firstLength,j=0;i < firstLength + secondLength;i++,j++)
	{
		newArr[i] = secondArr[j];
	}
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void printArray(int(&arr)[50], int length)
{
	for (int i = 0;i < length;i++)
	{
		cout << arr[i] << " ";
	}
}
void sortArray(int(&arr)[50], int length)
{
	for (int i = 0;i < length;i++)
	{
		int minIndex = i;
		for (int j = i + 1;j < length;j++)
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
void setArray(int(&arr)[25], int n)
{
	for (int i = 0;i < n;i++)
	{
		int a;
		cin >> a;
		arr[i] = a;
	}
}
int main()
{
	const int maxOfArray = 25;
	int length = 0;
	cout << "Length 1: ";cin >> length;
	int arr[maxOfArray];
	cout << "Set array 1: " << endl;
	setArray(arr, length);
	int length2 = 0;
	cout << "Length 2: ";cin >> length2;
	int secondArr[maxOfArray];
	cout << "Set array 2: " << endl;
	setArray(secondArr, length2);
	int newArr[maxOfArray * 2];
	int newLength = length + length2;
	mergeArrays(newArr, arr, length, secondArr, length2);
	sortArray(newArr, newLength);
	cout << "New array sorted: " << endl;
	printArray(newArr, newLength);
}
