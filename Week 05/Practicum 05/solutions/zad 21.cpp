using namespace std;
#include <iostream>

int squareRootToLower(int number)
{
	int i = 0;
	while(i*i<number)
	{
		i++;
	}
	return (i*i==number)?i:i-1;
}
int main()
{
	int n;
	cin >> n;
	cout << squareRootToLower(n);
}

