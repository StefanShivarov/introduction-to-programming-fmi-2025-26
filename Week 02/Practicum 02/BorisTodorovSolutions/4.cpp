#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	int positive_5_counter = 0;
	int sum = 0;
	while (positive_5_counter != 5)
	{
		int x;
		cin >> x;
		if (x > 0)
		{
			sum += x;
			positive_5_counter++;
		}
	}
	cout << sum;
}