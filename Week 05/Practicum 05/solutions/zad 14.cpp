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

	int parts = countDigits(original)-k;
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


void Switch(int& a, int& b, int k)
{
	int leftA = 0, rightA = 0;
	Separate(a, leftA, rightA,k);
	int leftB = 0, rightB = 0;
	Separate(b, leftB, rightB,k);
	int digitA = leftA % 10;
	int digitB = leftB % 10;
	leftA /= 10;
	leftB /= 10;
	leftA = leftA*10 + digitB;
	leftB = leftB*10 + digitA;

    int digRightA = countDigits(a)-k;
	int  digRightB = countDigits(b)-k;

	while (digRightA != 0)
	{
		leftA *= 10;
		digRightA--;
	}
	while (digRightB != 0)
	{
		leftB *= 10;
		digRightB--;
	}
	
	a = leftA + rightA;
	b = leftB +  rightB;



}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	Switch(n,m,k);
	cout << n << " " << m << endl;

}

