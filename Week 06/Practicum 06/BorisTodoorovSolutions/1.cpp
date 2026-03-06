#include <iostream>
using std::cin;
using std::cout;
using std::endl;
double averageOfArray(int(&arr)[50], int n)
{
	double sum = 0;
	for (int i = 0;i < n;i++)
	{
		sum += arr[i];
	}
	return sum/n;
}
void setArray(int(&arr)[50],int n)
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
	cout<<"Average : "<<averageOfArray(arr, n);
}