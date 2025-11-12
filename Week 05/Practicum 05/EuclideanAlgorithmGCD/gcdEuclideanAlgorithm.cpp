/*
*  Task:
*	Input: a stream of positive integers that ends when a negative number is entered
*	Output: the greatest common divisor (GCD) of all the entered positive numbers
*  Approach:
*	We use the fact that GCD(a, b, c) = GCD(a, GCD(b, c)). Set the GCD to initially be the first entered number.
*	After that, make the new GCD the GCD of the newly inputted number and the old GCD.
*	Repeat until a negative digit is entered (while loop).
*	To calculate the GCD of two numbers, we use Euclid's algorithm
*/

#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	a = a + b;
	b = a - b;
	a = a - b;
}

//Euclid's algorithm for gcd
int GCD(int a, int b)
{
	if (b > a) {
		swap(a, b);
	}

	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}

int main()
{
	cout << "Please enter the numbers that you want to find the GCD of. Once you are done, enter a negative number." << endl;
	int currentNumber;
	cin >> currentNumber;
	if (currentNumber <= 0)
	{
		cout << "The GCD of your numbers is " << currentNumber << endl;
		return 0;
	}

	int gcd = currentNumber;
	cin >> currentNumber;
	while (currentNumber > 0)
	{
		gcd = GCD(currentNumber, gcd);
		cin >> currentNumber;
	}

	cout << "The GCD of your numbers is " << gcd << endl;
	return 0;
}