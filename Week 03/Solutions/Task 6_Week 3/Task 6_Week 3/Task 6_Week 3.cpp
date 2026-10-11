#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int rows = 1; rows <= n; rows++)
	{
		for (int j = 1; j <= n - (n - rows); j++)
		{
			cout << j << " ";
		}
		cout << endl;
	}
	for (int secondRows = n ; secondRows >= 1; secondRows--)
	{
		for (int j = 1; j < n - (n - secondRows); j++)
		{
			cout << j << " ";
		}
		cout << endl;
	}
}
