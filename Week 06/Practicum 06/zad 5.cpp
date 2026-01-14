using namespace std;

#include <iostream>

bool IsinRange(int n);
void ReadArr(double arr[], int n);
void Swap(double& a, double& b);
void Sort(double arr[], int n);
void Print(double arr[], int n);

int main()
{
	int n;
	cin >> n;

	if (IsinRange(n))
	{
		double arr[50];
		ReadArr(arr, n);
		Sort(arr, n);
		Print(arr, n);
		
	}
	else cout << "Number must be in the range [1,50]";

}

bool IsinRange(int n)
{
	return (1 <= n && n <= 50);
}
void ReadArr(double arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}
void Swap(double &a, double &b)
{ 
	a = a + b;
	b = a - b;
	a = a - b;
}
void Sort(double arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (arr[i] > arr[j]) Swap(arr[i], arr[j]);
		}
	}
}
void Print(double arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}
