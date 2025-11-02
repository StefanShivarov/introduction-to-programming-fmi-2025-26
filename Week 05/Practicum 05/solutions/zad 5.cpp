using namespace std;

#include <iostream>


int Log(unsigned int n, unsigned int k)
{
	int result = k;
	int i;
	for (i = 0; result <= n; i++)
	{
		result *= k;
	}
	return i;

}

int main()
{
	int n, k;
	cin >> n >> k;
	cout << Log(n, k);
}

