using namespace std;
#include <iostream>


int getDivision(int first, int second)
{
	int	count = 0;
	while (first >= second)
	{
		first -= second;
		count++;
	}
	return count;
}
int main()
{
	int first, second;
	cin >> first >> second;
	cout << getDivision(first, second);
   
}

