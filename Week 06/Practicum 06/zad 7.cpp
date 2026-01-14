using namespace std;

#include <iostream>

bool IsinRange(int n);
void ReadArr(int arr[], int n);
int FindMax(int a, int b);
bool Linearly(int arr[], int arr2[], int n);


int main()
{
	int n;
	cin >> n;

	if (IsinRange(n))
	{
		int arr[50];
		ReadArr(arr, n);
		int arr2[50];
		ReadArr(arr2, n);
		Linearly (arr,arr2,n) ? cout << "Yes, the arrays are linearly dependent." :
			cout << "No, the arrays are not linearly dependent.";
		
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

bool Linearly(int arr[],int arr2[], int n)
{
	double dependence = arr2[0] / arr[0];
	
	for ( int i = 0; i < n; i++)
	{
		if (arr2[i] / arr[i] != dependence)return false;
	}
	return true;
}



