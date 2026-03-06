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

int concat(unsigned int first, unsigned int second)
{
	int digitsOfsecond = countDigits(second);
    while (digitsOfsecond>0)
    {
        first *= 10;
		digitsOfsecond--;
	}
	return first + second;
}
int main()
{
	int first, second;
	cin >> first >> second;
	cout << concat(first, second);
}

