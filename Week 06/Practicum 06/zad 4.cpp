using namespace std;
#include <iostream>


bool IsinRange(int n);
void ReadArr(char arr[], int n);
bool Symertic(char arr[], int n);

int main()
{

	int n;
	cin >> n;
	if (IsinRange(n))
	{
		char arr[50];
		ReadArr(arr, n);

		Symertic(arr, n) ? (cout << "Yes, the array is symmetric.") :
			(cout << "No, the array is not symmetric.");
	}
	else cout << "Number must be in the range [1,50]";

}
bool IsinRange(int n)
{
	return (1 <= n && n <= 50);
}
void ReadArr(char arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}
bool Symertic(char arr[], int n)
{
	for (int i = 0; i < n/2; i++)
	{
		if (arr[i] != arr[(n-1) - i]) return false;
	}
	return true;
}
