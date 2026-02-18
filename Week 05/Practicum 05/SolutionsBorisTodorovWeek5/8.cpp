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
void splitNumber(int num, int& left, int& right)
{
    int length=getLength(num);
    int dividor = 1;
    for (int i = 0;i < length / 2;i++)
    {
        dividor *= 10;
    }
    right = num % dividor;
    left = num / dividor;
}
int main()
{
    int num, left=0, right=0;
    cin >> num;
    splitNumber(num, left, right);
    cout << "left :" << left<<endl;
    cout << "right:" << right << endl;
}
