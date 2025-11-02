using namespace std;
#include <iostream>

int countDigits(int number)
{
	int count = 0;
	while (number > 0)
	{
		number /= 10;
		count++;
	}
	return count;
}

int sortDigits(unsigned int number)
{
	int newn = 0;
	for (int i = 0; i <= 9; i++)
	{
		int temp = number;
		while (temp > 0) {
			if (i == temp % 10)
			{
				newn = newn * 10 + i;
			}
			temp /= 10;
		}
	}
	return newn;
}
int main()
{
    int n;
	cin >> n;
	cout << sortDigits(n);
}

