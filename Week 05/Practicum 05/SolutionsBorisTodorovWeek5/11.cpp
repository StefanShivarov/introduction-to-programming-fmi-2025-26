#include <iostream>
using std::cin;
using std::cout;
using std::endl;

bool isSquareRoot(int number)
{
    for (int i = 0;i < number;i++)
    {
        if (i * i == number)
        {
            return true;
        }
        else if (i * i > number)
        {
            return false;
        }
    }
}
int main()
{
    int num = 0;
    cin >> num;
    cout << isSquareRoot(num);
}
