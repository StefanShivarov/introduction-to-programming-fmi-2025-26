#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	//int element = 1;
	for (int rows = 1; rows <= n; rows++)
	{
		for (int i = 1; i <= n; i++)
		{
			
			if (i == rows) {
				cout << rows;
			}
			else if (i > rows)
			{
				cout << ".";
			}
			else {
				cout << "*";
			}
		}
		//element++;
		/*for (int j = 1; j <= n - rows; j++)
		{
			cout << ".";
		}*/
		cout << endl;
	}
}
