#include <iostream>
using std::cin;
using std::cout;
using std::endl;
bool isArrayMonotonicallyDeclining(int(&arr)[50], int n)
{
	int a = arr[0];
	for (int i = 0;i < n;i++)
	{
		if (arr[i] <= a)
		{
			a = arr[i];
		}
		else
		{
			return false;
		}
	}
	return true;
}
void setArray(int(&arr)[50], int n)
{
	for (int i = 0;i < n;i++)
	{
		int a = 0;
		cin >> a;
		arr[i] = a;
	}
}
int main()
{
	int n = 0;
	cin >> n;
	int arr[50];
	setArray(arr, n);
	if (isArrayMonotonicallyDeclining(arr, n))cout << "The series is montonically decreasing.";
	else cout << "The series is not montonically decreasing.";
}
