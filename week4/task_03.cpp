#include <iostream>
using namespace std;

int askUser(const int from, const int to)
{
    int number;
    do
    {
        cout << "[" << from << ", " << to << "]: ";
        cin >> number;
        if (number < from || number > to)
        {
            cout << "invalid" << endl;
        }
    } while (number < from || number > to);
    return number;
}

int main()
{
    int from, to;
    cout << "from: ";
    cin >> from;
    cout << "to: ";
    cin >> to;
    cout << "valid number: " << askUser(from, to) << endl;
    return 0;
}