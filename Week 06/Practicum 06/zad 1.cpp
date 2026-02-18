using namespace std;

#include <iostream>

bool IsinRange(int n);
void ReadArr(int arr[], int n);
double Average(int arr[], int n);

int main()
{
	int n;
	cin >> n;

	if (IsinRange(n))
	{
		int arr[50];
		ReadArr(arr, n);
		cout << "Average: " << Average(arr, n);
	}
	else cout << "Number must be in the range [1,50]";

}

bool IsinRange(int n)
{
	return (1 <= n && n<= 50);
}
void ReadArr(int arr[], int n)
{
	for (int i = 0; i <n; i++)
	{
		cin >> arr[i];
	}
}
double Average(int arr[], int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum / n;
}
