#include <iostream>
using namespace std;

int Cifra(char n)
{
	if (n >= '0' && n <= '9')
	{
		return n-'0';
	}
	else
	{
		return -1;
	}
}
int main()
{
	char a;
	cin >> a;
	cout << Cifra(a);
}