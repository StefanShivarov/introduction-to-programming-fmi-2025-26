#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	int negative_3_counter = 0;
	int min = 0;
	while (negative_3_counter != 3)
	{
		int x;
		cin >> x;
		if (x < 0)
		{
			if (x < min)
			{
				min = x;
			}
			negative_3_counter++;
		}
		else
		{
			negative_3_counter = 0;
			min = 0;
		}
	}
	cout << min;
}