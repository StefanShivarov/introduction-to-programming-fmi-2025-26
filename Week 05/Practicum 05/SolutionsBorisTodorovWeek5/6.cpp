#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int getLength(int number)
{
    int temp = number;
    int length = 0;
    while (temp >= 1)
    {
        length++;
        temp /= 10;
    }
    return length;
}
int getDigitOnPosition(int number, unsigned int position)
{
    int length = getLength(number);
    int numOfOperations=length - position;
    for (int i = 0;i < numOfOperations;i++)
    {
        number /= 10;
    }
    return number % 10;
}
int main()
{
    int num;
    cin >> num;
    int position;
    cin >> position;
    cout << getDigitOnPosition(num,position);
}
