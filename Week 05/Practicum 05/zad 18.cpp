using namespace std;
#include <iostream>


bool isDivisableByValue(int number, int divisor)
{
	
	while (number >= divisor)
	{
		number -= divisor;
	}
	return (number == 0);
	
}
int main()
{
	int n, devisor;
	cin >> n >> devisor;
	cout << (isDivisableByValue(n, devisor)? "true":"false");
}

