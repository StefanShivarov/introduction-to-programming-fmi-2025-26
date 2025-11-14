using namespace std;
#include <iostream>

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

int lcm(int first, int second)
{
	if (first < second) swap(first, second);
    for (int i = first; i<=first*second; i++)
    {
       if (i%first==0 && i%second==0)
       {
           return i;
	   }
	}
}
int main()
{
	int a, b;
	cin >> a >> b;
	cout << lcm(a, b);
}

