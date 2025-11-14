

#include <iostream>
using namespace std;
void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;

}
int main()
{
	int a, b;
	cout << "Enter a:";

	cin >> a;
	cout << "Enter b:";
	cin>> b;
	swap(a, b);
	cout << "a:" << a << endl << "b:" << b;
}

