#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int element = 1;
	for (int rows = 1; rows <= n; rows++)
	{
		for (int i = 1; i <= n - (n - rows); i++)
		{
		cout << element << " ";

		element++;
		}
	cout << endl;
	}
}