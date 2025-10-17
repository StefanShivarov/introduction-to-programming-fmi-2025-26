
#include <iostream>

using  std::cin;
using std::cout;
using std::endl;
#include <cmath>

int main()
{
	//zad13

	/*int n, sum = 0;
	cin >> n;

	for (int i = 0; i <= n; i++)
	{

		if (i % 10 == 6 || i % 10 == 8)
	    {
			sum += i;
		}

	}

	cout << sum;*/


	//zad14
	/*int n, count = 0;
	cin >> n;
	for (int  i = 1; i <= n; i++)
	{

		if (n%i==0)
		{
			count++;
		}
	}
	cout << count;*/

	//zad15
	/*int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int copy = i;
		int digitSum = 0;
		while (copy!=0)
		{
			digitSum += copy % 10;
			copy /= 10;

		}

		if (digitSum % 2 == 0)
		{
			cout << i << " ";
		}
	}*/



	//zad 16

		/*int n;
		cin >> n;
		int copyEnd = 1;
		for (int i = 1; i <= n; i++)
		{
			int end = 0;
			if (i % 2 == 0)
			{

					end = i * (i / 2) + (i/2);
			} else
				if(i % 2 != 0)
				{
					end = (i != 1) ? (i * ((i+1) / 2)) : i;
				}
			if (i == 1)
			{
				cout <<1 << " ";
			}
			for ( int j = copyEnd+1; j <= end; j++)
			{
				cout << j<< " ";
			}
			cout << endl;
			copyEnd = end;
		}*/




		//zad 17
	/*int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j =0; j < n; j++)
		{
			if (j <= i)
			{
				cout << 1 << " ";
			}
			else {
				cout << 0 << " ";
			}
		}
		cout << endl;
	}*/


	//zad18
/*	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j << " ";
		}

		cout << endl;
	}

	for (int i = n-1; i >= 1; i--)
	{
		for (int l = 1; l <= i; l++)
		{
			cout << l << " ";
		}
		cout << endl;
	}*/


	//zad19
	/*int n;
	cin >> n;
	for (int i = 1;  i <= n; i++)
	{
		for (int j = 1; j <i; j++)
		{
			cout << "*";
		}

		cout << i;

		for (int l = n-i; l >0; l--)
		{
			cout << ".";
		}

			cout << endl;
	}*/

}
	




