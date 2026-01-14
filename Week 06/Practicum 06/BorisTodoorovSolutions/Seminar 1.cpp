#include <iostream>
using std::cin;
using std::cout;
using std::endl;
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void transformLeftSide(int(&arr)[50], int length)
{
	int leftLength = length / 2 + length % 2;
	for (int i = 0;i < leftLength/2;i++)
	{
		swap(arr[i], arr[leftLength - i - 1]);
	}
}
void transformRightSide(int(&arr)[50], int length)
{
	int leftLength = length / 2 + length % 2;
	for (int i = leftLength;i < (length + leftLength)/2;i++)
	{
		swap(arr[i], arr[length - i+leftLength - 1]);
	}
}
void printArray(int(&arr)[50], int length)
{
	for (int i = 0;i < length;i++)
	{
		cout << arr[i] << " ";
	}
}
void transformArray(int(&arr)[50], int length)
{
	transformLeftSide(arr, length);
	transformRightSide(arr, length);
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
int main()
{
	const int maxOfArray = 50;
	int length = 0;
	cin >> length;
	int arr[maxOfArray];
	setArray(arr, length);
	transformArray(arr, length);
	printArray(arr, length);
}

