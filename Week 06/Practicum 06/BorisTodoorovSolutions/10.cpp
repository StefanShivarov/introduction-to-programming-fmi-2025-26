#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int splitNumberIntoArray(int n, int(&arr)[50])//backwards
{
	int i = 0;
	if (n == 0)
	{
		arr[0] = 0;
		i++;
	}
	else
	{
		while (n >= 1)
		{
			arr[i] = n % 10;
			n /= 10;
			i++;
		}
	}
	return i;
}
bool LexComparison(int a, int b)
{
	int firstArr[50];
	int secondArr[50];
	int length=splitNumberIntoArray(a, firstArr);
	int length2=splitNumberIntoArray(b, secondArr);
	int smallerLength = length < length2 ? length : length2;
	for (int i = 0;i < smallerLength;i++)
	{
		if (firstArr[length-i-1]<secondArr[length2-i-1])
		{
			return true;
		}
		else
		{
			return false;
		}
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
void sortArrayLex(int(&arr)[50], int length, bool (*comparatorFunc)(int, int))
{
	for (int i = 0;i < length;i++)
	{
		int minIndex = i;
		for (int j = i + 1;j < length;j++)
		{
			if (comparatorFunc(arr[j],arr[minIndex]))
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
	cout << "Length: ";cin >> length;
	int arr[maxOfArray];
	cout << "Set array: " << endl;
	setArray(arr, length);
	sortArrayLex(arr, length,LexComparison);
	printArray(arr, length);
}

