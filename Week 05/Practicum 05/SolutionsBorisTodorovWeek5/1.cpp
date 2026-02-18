#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    int a;
    int b;
    cout << "A = ";
    cin >> a;
    cout << "B = ";
    cin >> b;
    swap(a, b);
    cout << "Swapped values:" << endl;
    cout << "A = ";
    cout << a<<endl;
    cout << "B = ";
    cout << b;

}
