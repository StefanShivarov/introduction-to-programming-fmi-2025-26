using namespace std;

#include <iostream>

bool IsinRange(int n);
void ReadArr(int arr[], int n);
bool IsIncreasing(int arr[], int n);
bool BinarySearch(int arr[], int n, int x);

int main()
{
	int n;
	cin >> n;

	if (IsinRange(n))
	{
		int arr[50];
		ReadArr(arr, n);
		int x;
		cout << "x: ";
		cin >> x;
		if (IsIncreasing(arr, n))
		{
			BinarySearch(arr,n,x)? (cout<<"Yes "<<x<<" is in the array.")
				:(cout<<"No "<<x <<" is not in the array.");
		}
		else cout<<"Array not arranged";
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
bool BinarySearch(int arr[], int n, int x)
{
	int leftIndex = 0, rightIndex = n - 1;
	while (leftIndex <= rightIndex) {
		
		int midIndex = leftIndex + (rightIndex - leftIndex) / 2; 

		if (arr[midIndex] == x) {
			return midIndex;
		}

		if (arr[midIndex] < x) {
			leftIndex = midIndex + 1;
		}
		else {
			rightIndex = midIndex - 1;
		}
	}
	return false;
}
bool IsIncreasing(int arr[], int n)
{
	for (int  i = 0; i < n-1; i++)
	{
		if (arr[i]>arr[i+1]) return false;
	}
	return true;
}
