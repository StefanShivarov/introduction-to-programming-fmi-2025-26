#include <iostream>
using namespace std;

int KDigit(int n, int k)
{
	int digits = 0;
	int temp = n;
	while (temp > 0)
	{
		digits++;
		temp /= 10;
	}
	for (int i = 0; i < digits - k; i++)
	{
		n /= 10;
	}
	return n % 10;
}
int main()
{
	int n, k;
	cin >> n >> k;
	cout << KDigit(n, k);
}