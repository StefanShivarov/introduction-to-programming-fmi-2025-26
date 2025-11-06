#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int squareRootToLower(int number)
{
    int root = 0;
    while (root * root <= number)
    {
        root++;
    }
    return root - 1;
}
int main()
{
    int n;
    cin >> n;
    cout << squareRootToLower(n);
}
