using namespace std;
#include <iostream>


bool isSquareRoot(int number)
{

	for (int i = 0; i <= number/2; i++)
	{
		if (number ==1 ||number == i * i) return true;
	}
	return false;
}
int main()
{
	int n;
	cin >> n;
	cout << (isSquareRoot(n) ? "true" : "false");

}
