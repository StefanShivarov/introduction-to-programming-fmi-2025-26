using namespace std;
#include <iostream>


int gcd(int first, int second)
{
	
		int start = (first < second) ? first : second;
	for (int i = start; i >= 0; i--)
	{
		if (first % i == 0 && second % i == 0)
		{
			return i;
		}
	}
}
int simplifyAndSum(int& x, int& y)
{
	int del = gcd(x, y);
	x /= del;
	y /= del;
	return x + y;

}
int main()
{
    int a = 16, b = 20;
    int result = simplifyAndSum(a, b);
    cout << a << ' ' << b << ' ' << result;
}

