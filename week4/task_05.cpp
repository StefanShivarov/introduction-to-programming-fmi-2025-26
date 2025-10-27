#include <iostream>
using namespace std;

bool IsPalindrome(int n)
{
	int original = n;
	int reversed = 0;
	while (n > 0)
	{
		int digit = n % 10;
		reversed = reversed * 10 + digit;
		n = n / 10;
	}
	return original == reversed;
}
int main()
{
	int n;
	cin >> n;
	if (IsPalindrome(n)) cout << "true";
	else cout << "false";
}