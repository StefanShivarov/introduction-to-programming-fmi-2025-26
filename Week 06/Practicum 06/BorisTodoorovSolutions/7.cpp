#include <iostream>
using std::cin;
using std::cout;
using std::endl;
bool arraysLinearlyDependant(int(&firstArr)[50], int(&secondArr)[50], int length)
{
	double k = (double(firstArr[0]) / double(secondArr[0]));
	for (int i = 1;i < length;i++)
	{
		if (secondArr[i] * k != firstArr[i])
		{
			return false;
		}
	}
	return true;
}
void setArray(int(&arr)[50], int length)
{
	for (int i = 0;i < length;i++)
	{
		int a;
		cin >> a;
		arr[i] = a;
	}
}
int main()
{
	const int maxOfArray = 50;
	int length = 0;
	cin >> length;
	int firstArr[maxOfArray],secondArr[maxOfArray];
	setArray(firstArr, length);
	setArray(secondArr, length);
	if (arraysLinearlyDependant(firstArr, secondArr, length))cout << "Yes, the arrays are linearly dependant";
	else cout << "No, the arrays are not linearly dependant";

}
