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
int concat(unsigned int first, unsigned int second)
{
    int length = getLength(second);
    for (int i = 0;i < length;i++)
    {
        first *= 10;
    }
    return first + second;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << concat(a, b);
}
