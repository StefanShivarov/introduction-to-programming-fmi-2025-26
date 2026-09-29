#include <iostream>
using namespace std;

int main()
{
	//zadacha 13
	/*int n;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i % 10 == 6 || i % 10 == 8)
		{
			sum+=i;
		}
	}
	cout << sum << endl;*/

	//zadacha 14
	/*int n;
	cin >> n;
	int br = 0;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0) br++;
	}
	cout << br;*/

	//zadacha 15
	/*int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int sum=0;
		int a = 0;
		int b = i;
		while (b > 0)
		{
			a = b % 10;
			sum+= a;
			b = b / 10;
		}
		if (sum % 2 == 0) cout << i << " ";
	}*/

	//zadacha 16
	/*int n;
	cin >> n;
	int current = 1;
	for (int i = 1; i <= n; i++)
	{
		for(int j=1; j<=i;j++)
		{
			cout << current<<" ";
			current++;
		}
		cout << endl;
	}*/

	//zadacha 17
	/*int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j <= i) cout << "1 ";
			else cout << "0 ";
		}
		cout << endl;
	}*/

	//zadacha 18
	/*int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j << " ";
		}
		cout << endl;
	}
	for(int i=n-1; i>=1;i--)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j << " "; 
		}
		cout << endl;
	}*/

	//zadacha 19
	/*int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j == i) cout << i << " ";
			else if (j <= i) cout << "* ";
			else cout << ". ";
		}
		cout << endl;
	}*/
}
