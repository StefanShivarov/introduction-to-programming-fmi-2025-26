using namespace std;
#include <iostream>

bool IsinRange(int n);
void ReadArr(int arr[], int n);
bool Elements(int arr[], int n);

int main()
{
	int n;
	cin >> n;
	if (IsinRange(n))
	{
		int arr[50];
		ReadArr(arr, n);
		Elements(arr, n) ? cout << "Yes, the sequence consists of distinct elements." 
			: cout << "No, the sequence does not consist of distinct elements.";

	}
	else cout << "Number must be in the range [1,50]";
   
}
bool IsinRange(int n)
{
	return (1 <= n && n <= 50);
}
void ReadArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}
bool Elements(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j) 
			{
				if (arr[i] == arr[j])
					return false;
			}
		}
	}
	return true;
}
