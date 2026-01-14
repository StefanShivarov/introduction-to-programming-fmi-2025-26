#include <iostream>
using std::cin;
using std::cout;
using std::endl;
bool isArrayDistinct(int(&arr)[50], int n)
{
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (arr[i] == arr[j]&&i!=j)
			{
				return false;
			}
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
	if (isArrayDistinct(arr, n))cout << "Yes, the sequence consists of distinct elements";
	else cout << "No, the sequence does not consist of distinct elements.";
}
