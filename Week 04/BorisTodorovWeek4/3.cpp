#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int askUser(const int from, const int to)
{
    int n;
    do
    {
        cout << "Enter number:";
        cin >> n;
    } while (!(n>from && n < to));
        return n;
}
int main()
{
    int from;
    int to;
    cout << "from:";cin >> from;
    cout << "to:";cin >> to;
    std::cout <<askUser(from,to );
}