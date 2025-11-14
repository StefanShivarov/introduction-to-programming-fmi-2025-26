using namespace std;
#include <iostream>

bool IsinRange(int n);
void ReadArr(int arr[], int n);
bool  Decreasing(int arr[], int n);
int main()
{
	int n;
	cin >> n;
	if (IsinRange(n))
	{
		int arr[50];
		ReadArr(arr, n);
		Decreasing(arr,n) ? (cout << "The series is monotonically decreasing.") : (cout << "The series is not monotonically decreasing.");

	}else  cout << "Number must be in the range [1,50]";

}
bool IsinRange(int n)
{
	return (1<=n&&n<=50);
}
void ReadArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

bool  Decreasing(int arr[], int n)
{

	for (int i = 1; i < n; i++)
	{
		if (arr[i]>arr[i-1]) return false;
	}
	return true;
}