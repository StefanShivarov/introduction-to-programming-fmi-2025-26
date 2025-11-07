#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int absoluteValue(int number)
{
    if (number < 0)
    {
        return number * -1;
    }
    else
    {
        return number;
    }
}
int main()
{
    int num;
    cin >> num;
    cout << absoluteValue(num);
}
