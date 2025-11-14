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
void Separate(int original, int& left, int& right)
{
	
	int parts = countDigits(original)/ 2;
	int reversed = 0;
	for (int i = 0; i < parts; i++)
	{
		
		reversed+= original % 10;
		original /= 10;
		reversed *= 10;
		
	}
	while(reversed > 0)
	{
		right += reversed % 10;
		reversed /= 10;
		right *= 10;
	}
	right /= 10;
	left = original;

}
int main()
{
	int original, left = 0, right = 0;
	cin >> original;
   Separate(original, left, right);
   cout <<"left = " <<left << ", right = " << right;
}

