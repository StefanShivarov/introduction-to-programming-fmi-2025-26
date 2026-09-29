#include <iostream>
using namespace std;

int power(int base, int exponent)
{
	int result = 1;
	for (int i = 0; i < exponent; i++)
	{
		result *= base;
	}
	return result;
}
int concat(int first, int second)
{
	int digits = 0;
	int temp = second;
	if (temp == 0)
	{
		digits = 1;
	}
	else
	{
		while (temp > 0)
		{
			digits++;
			temp /= 10;
		}
	}
	int result = first * power(10, digits) + second;
	return result;
}
int main()
{
	int first, second;
	cin >> first >> second;
	cout << concat(first, second);
}