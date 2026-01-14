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

int getDigitOnPosition(int number, unsigned int position)
{
	int countDig = countDigits(number);
	int pos = countDig - position;
    while (pos > 0)
    {
        number /= 10;
        pos--;		
    }
	return number % 10;
}
int main()
{
unsigned int number, position;
	cin >> number >> position;
	cout << getDigitOnPosition(number, position);
}

