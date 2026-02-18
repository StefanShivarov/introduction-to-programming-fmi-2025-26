using namespace std;
#include <iostream>


void ReadArr(int arr[], int n);
void Connect(int arr3[], int arr[], int arr2[], int l1, int l2, int l3);
void Swap(int& a, int& b);
void Sort(int arr[], int n);
void Print(int arr[], int n);

int main()
{
	int const l1 = 5;
	int arr[l1];
	int const l2 = 7;
	int arr2[l2];
	ReadArr(arr, l1);
	ReadArr(arr2, l2);
	int const l3 = l1 + l2;
	int arr3[l3];
	Connect(arr3, arr, arr2, l1, l2, l3);
	Sort(arr3, l3);
	Print(arr3,l3);
}

void ReadArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}
void Connect(int arr3[],int arr[], int arr2[], int l1,int l2, int l3)
{
	for (int i = 0; i < l1; i++)
	{
		arr3[i] = arr[i];
	}
	for (int i = 0; i < l2; i++)
	{
		arr3[l1+ i] = arr2[i];
	}
}
void Swap(int& a, int& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}
void Sort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (arr[i] > arr[j]) Swap(arr[i], arr[j]);
		}
	}
}
void Print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}