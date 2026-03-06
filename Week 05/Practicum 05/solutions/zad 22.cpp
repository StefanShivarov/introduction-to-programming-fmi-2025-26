using namespace std;
#include <iostream>


bool isPrime(int n)
{
	
    for (int  i = 2; i <= n/2; i++)
    {
        if (n % i == 0) return false;
    }
	return true;
}

void Fact (int n)
{
    int original = n;
    for (int  i = 2; i < n/2; i++)
    {   
        if (isPrime(i))
        {
            while (n%i==0)
            {
				if (n == original) cout << i;
                else cout << "." << i;
   
                n /= i;
            }
        }
    }
}


int main()
{
    int n;
    cin >> n;
     Fact(n);

}
