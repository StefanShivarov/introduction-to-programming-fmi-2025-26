#include <iostream>
using std::cin;
using std::cout;
using std::endl;
bool searchArray(int(&arr)[50],int length,int key)
{
	int leftIndex=0,rightIndex=length-1,midIndex=0;
	while (leftIndex<=rightIndex)
	{
		int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
		if (arr[midIndex] == key)
		{
			return true;
		}
		if (key < arr[midIndex])
		{
			rightIndex = midIndex-1;
		}
		else
		{
			leftIndex = midIndex + 1;
		}
	}
	return false;
}
void setArray(int(&arr)[50], int length)
{
	for (int i = 0;i < length;i++)
	{
		int a;
		cin >> a;
		arr[i] = a;
	}
}
int main()
{
	const int maxOfArray = 50;
	int length = 0,n=0;
	cin >> length;
	int arr[maxOfArray];
	setArray(arr, length);
	cout << "Search for: ";cin >> n;
	if (searchArray(arr, length, n)) cout << "Yes, " << n << " is in the array";
	else cout << "No, " << n << " is not in the array";
}
