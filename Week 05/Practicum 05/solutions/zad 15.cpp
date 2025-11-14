using namespace std;
#include <iostream>


int countDigits(int number)
{
	int count = 0;
	while (number > 0)
	{
		number /= 10;
		count++;
	}
	return count;
}
void Separate(int original, int& left, int& right, int k)
{

	int parts = countDigits(original) - k;
	int reversed = 0;
	for (int i = 0; i < parts; i++)
	{

		reversed += original % 10;
		original /= 10;
		reversed *= 10;

	}
	while (reversed > 0)
	{
		right += reversed % 10;
		reversed /= 10;
		right *= 10;
	}
	right /= 10;
	left = original;

}

void Transform(int &a, int &b, int k)
{
	int leftA = 0, rightA = 0;
	Separate(a,leftA ,rightA, k);

	a = leftA;
	for (int i = 0; i < countDigits(b); i++)
	{
		rightA *= 10;
	}
	b = rightA + b;
}

int main()
{
	int a, b, k;
	cin >> a >> b >> k;

	Transform(a, b, k);
	cout << "a = "<<a << ", b = " << b << endl;
}

