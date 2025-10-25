#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n;
    int m;
    cin >> n;
    m = n;
    int i = 0;
    while (n >= 1)
    {
       if (n % 2 == 1)
       {
         cout << "2^" <<i;
         if (n >= 2)
         {
             cout << " + ";
         }
       }
       n /= 2;
       i++;
    }

    
}
