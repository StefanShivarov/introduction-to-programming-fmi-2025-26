#include <iostream>
using namespace std;

char GlavnaBukva(char ch)
{
	if (ch >= 'a' && ch <= 'z')
	{
		return ch - ('a' - 'A');
	}
	else return ch;
}
int main()
{
	char a;
	cin >> a;
	cout << GlavnaBukva(a);
}