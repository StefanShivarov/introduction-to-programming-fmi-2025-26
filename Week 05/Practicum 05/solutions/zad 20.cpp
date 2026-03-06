using namespace std;
#include <iostream>


int Absolute(int a)
{
	if (a < 0)
	{
		return -a;
	}
	else
	{
		return a;
	}
}
int Closest(int n)
{
	int i = 1;
	while (i < n-i)
	{
		i *= 2;
	}
	if (n - i < Absolute(n - (i * 2)))
	{
		return i;
	}
	else 
	{
		return i * 2;
	}
}

int main()
{
    int n;
    cin >> n;
	cout << Closest(n);

}

