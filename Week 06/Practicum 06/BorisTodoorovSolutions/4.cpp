#include <iostream>
using std::cin;
using std::cout;
using std::endl;
bool isArraySymmetrical(char(&arr)[50], int n)
{
	int k = n / 2;
	for (int i = 0;i < k;i++)
	{
		if (arr[i] != arr[n - i-1])
		{
			return false;
		}
	}
	return true;
}
void setArray(char(&arr)[50], int n)
{
	for (int i = 0;i < n;i++)
	{
		char a;
		cin >> a;
		arr[i] = a;
	}
}
int main()
{
	int n = 0;
	cin >> n;
	char arr[50];
	setArray(arr, n);
	if (isArraySymmetrical(arr, n))cout << "Yes, array is symmetric";
	else cout << "No, array is not symmetric";
}
