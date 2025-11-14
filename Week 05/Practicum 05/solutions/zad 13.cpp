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
int simplify(int& x, int& y, int (*operation)(int, int))
{
	int del = gcd(x, y);
	x /= del;
	y /= del;
	return operation(x, y);	

}
int main()
{
		int a = 16, b = 20;
		int result = simplify(a, b, [](int x, int y) { return x * y; });
		cout << a << ' ' << b << ' ' << result;
	
}



