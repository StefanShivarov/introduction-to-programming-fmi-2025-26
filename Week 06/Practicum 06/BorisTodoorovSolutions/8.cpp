#include <iostream>
using std::cin;
using std::cout;
using std::endl;
bool isArraySymmetrical(int(&arr)[12], int n)
{
	int k = n / 2;
	for (int i = 0;i < k;i++)
	{
		if (arr[i] != arr[n - i - 1])
		{
			return false;
		}
	}
	return true;
}
int splitNumberIntoArray(int n, int(&arr)[12])
{
    int i = 0;
    while (n >= 1)
    {
        arr[i] = n % 10;
        n /= 10;
		i++;
    }
	return i;
}

int main()
{
    int n = 0;
    cin >> n;
    int arr[12];
	int length = splitNumberIntoArray(n,arr);
	if (isArraySymmetrical(arr, length))cout << "Yes";
	else cout << "No";

}