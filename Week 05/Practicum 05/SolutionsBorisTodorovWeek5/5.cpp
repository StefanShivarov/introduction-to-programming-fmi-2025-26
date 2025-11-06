#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int log(int n, int k)
{
	int x=k;
	int i = 0;
	while (x <= n)
	{
		x *= k;
		i++;
	}
	return i;
}
int main()
{
	int n, k;
	cin >> n >> k;
	cout << log(n, k);
}
