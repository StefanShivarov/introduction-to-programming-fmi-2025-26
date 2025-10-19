#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int mainDiagonal = 1;
	for (int rows = 1; rows <= n; rows++)
	{
		for (int i = 1; i <= n - (n - rows); i++)
		{
			cout << mainDiagonal << " ";
		}
		for (int j = 1; j <= n - rows; j++)
		{
			cout << 0 << " ";
		}
		cout << endl;
	}
}