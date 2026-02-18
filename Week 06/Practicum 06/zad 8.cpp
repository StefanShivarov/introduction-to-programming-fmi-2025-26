using namespace std;

#include <iostream>

bool IsinRange(int n);
void ReadArr(int arr[], int n);
bool IsPalindrome(int arr[], int n);
int CountDig(int n);
bool IsPalindrome(int arr[], int n);

int main()
{
	int n;
	cin >> n;

	if (IsinRange(CountDig(n)))
	{
		int arr[12];
		
		IsPalindrome(arr,n) ? cout << "yes" : cout << "no";
	}
	else cout << "Digit's number must be in the range [1,12]";

}

bool IsinRange(int n)
{
	return (1 <= n && n <= 12);
}
void ReadArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}
bool IsPalindrome( int arr[], int n)
{
	int count = CountDig(n);
	for (int i = 0; i < count; i++)
	{
		arr[i] = n % 10;
		n /= 10;
	}
	for (int i = 0; i < count; i++)
	{
		if (arr[i] != arr[count - 1 - i]) return false;
	}return true;
}
int CountDig(int n)
{
	int count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return count;
}
