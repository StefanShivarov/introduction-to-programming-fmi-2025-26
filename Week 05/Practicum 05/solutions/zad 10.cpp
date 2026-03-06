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
	for (int i = first; i <= first * second; i++)
	{
		if (i % first == 0 && i % second == 0)
		{
			return i;
		}
	}
}
int gcd(int first, int second)
{
	if (first < second) swap(first, second);
	for (int i = first; i >= 0; i--)
	{
		if (first % i == 0 && second % i == 0)
		{
			return i;
		}
	}
}
int main()
{
    int n, num; 
    cin >> n;
	int templcm = 1 ;
	int tempgcd = 0;
	for (int i = 0; i <n ; i++)
	{
		cin >> num;
		templcm = lcm(templcm, num);
		tempgcd = gcd(tempgcd, num);
	}

	cout << "GCD: "<<tempgcd << endl<< "LMC: " << templcm;
}

