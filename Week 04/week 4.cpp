
#include <iostream>
using namespace std;




		bool canFormATriangle(int a, int b, int c)
		{
			return ((a + b > c) && (b + c > a) && (c + a > b));

		}


		int Calculate(const int a, const int b, char action )
		{
			switch(action)
			{

			case ('+'): return  a + b;
			case ('*'): return a * b;
			case ('-'): return a - b;
			case ('/'): return a / b;

			}
		}

		int ascii(char symbol)
		{

			return symbol;

		}


		int askUser(const int from, const int to)
		{
			int n;
			cin >> n;
	
			while (n<from || n>to)
			{
				cin >> n;
			}
			return n;

		}

		int CountDigits(int n)
		{
			int count = 0;
			while (n != 0)
			{
				n /= 10;
				count++;
			}
			return count;
		}

		int PowTen(int n)
		{
			int a = 1;
			while (n != 0)
			{
				n--;
				a *= 10;
			}
			return a;
		}
		
		bool isPalindrome(unsigned int n)
		{

			int count = CountDigits(n);
			for (int i = 0; i <= count /2; i++)
			{
	
				if ((n / PowTen(i) % 10) != (n / PowTen(count - i-1) % 10))
				{
					return false;
				}
	
			}
	    }

		char toUpper(char c)
		{ 
			if (c >= 'a' && c <= 'z')
			{
				return c - ('a' - 'A');
			}
			else
			{
				return c;
			}
		}

		int IsDigit(char c)
		{
			if (c >= '0' && c <= '9')
			{
				return c-'0';
			}return   -1;
		}

		int Digit(int n, int k)
		{
			int count = CountDigits(n);
			int remove = count - k;
			while (remove != 0)
			{
				remove--;
		   	  n /= 10;
      		}
			return n % 10;

		}

		int concat(int first, int second)
		{
			int count = CountDigits(second);
			return first * PowTen(count) + second;
		}


		int Sort(int n)
		{
			int result = 0;
			for (int i = 0; i <= 9; i++)
			{
				int copyn = n;
				while (copyn != 0) {
					int digit = copyn % 10;

					if (digit == i)
					{
						result = result * 10 + digit;
					}
					copyn /= 10;
				}
			}
			return result;
		}


		int SumDigits(long long n)
		{
			int sum = 0;
			while (n!=0)
			{
				sum += n % 10;	
				n /= 10;
			}
			return sum;
		}



		bool isPrime(int n)
		{
			
			for ( int i = 2; i <= n/2; i++)
			{
				if (n % i == 0) return false;
			}
		
		}

		int SumOfPrime(int n)
		{
			int sum = 0;
			for (int i = 0; i < n; i++)
			{
				if (isPrime(i))
				{ 
					sum += i;
				}
			}
			return sum;
		}
int main()
{

	/*//zad 1
	int a, b;
	char c;
	cin >> a >> c >> b;
	cout<<Calculate(a, b, c);*/

	//zad 2
	/*char a;
	cin >> a;
	cout << ascii(a);*/

	//zad 3
	/*int from, to;
	cin >> from >> to;
	cout << askUser(from, to);*/


	//zad 4
	/*int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if ( canFormATriangle(a,b,c))
		{
			cout << a << " " << b << " " << c << endl;
		}

	}*/

	//zad 5
	/*int n;
	cin >> n;
	cout << (isPalindrome(n)? "is palindrome":"is not palindrome");*/

	//zad 6
	/*char c;
	cin >> c;
	cout<<toUpper(c);*/

	//zad 7
	/*char c;
	cin >> c;
	cout << IsDigit(c);*/
	
	//zad 8
	/*int n, k;
	cin >> n >> k;
	cout << Digit(n, k);*/

	// zad 9
	/*int first, second;
	cin >> first >> second;
	cout << concat(first, second);*/

	//zad 10
	/*int n;
	cin >> n;
	cout << Sort(n);*/

	//zad11
	/*long long n;
	cin >> n;	
	while (n > 10)
	{
		int sum = SumDigits(n);
		n = sum; 
	}

	cout << n;
	*/

	//zad 12
	/*int n;
	cin >> n;
	cout << (isPrime (n)? "yes":"no");*/
	
	//zad 13
	/*int n;
	cin >> n;
	cout << SumOfPrime(n);*/

}







void printNumbersByPredicate(int a,int b,int c,
	bool(*func)(int,int,int))//podawame na funkciqta druga funkciq
{
	if (func(a,b,c))
	{
		cout << a << " " << b << " " << c << endl;
	}
}


