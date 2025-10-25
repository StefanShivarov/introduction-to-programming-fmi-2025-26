#include <iostream>
#include <math.h>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	int a;
	int b;
	int c;
	double D;
	double x1;
	double x2;
	cin >> a;
	cin >> b;
	cin >> c;
	D = b * b - 4 * a * c;
	x1 = (-b + sqrt(D)) / (2 * a);
	x2 = (-b - sqrt(D)) / (2 * a);
	cout << a;cout << "x^2 + ";cout << b;cout << "x + ";cout << c << endl;
	cout << "x1 = ";cout << x1<<endl;
	cout << "x2 = ";cout << x2;
}