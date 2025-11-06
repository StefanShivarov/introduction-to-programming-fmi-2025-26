#include <iostream>
using std::cin;
using std::cout;
using std::endl;
void nod(int a,int& nod)
{
    for (int i = nod;i > 0;i--)
    {

        if (a % i == 0 && nod % i == 0)
        {
            nod = i;
            return;
        }
    }
}
void nok(int b,int& nok)
{
    for (int i = b;i <= nok*b;i++)
    {
        if (i % b == 0 && i % nok == 0)
        {
            nok = i;
            return;
        }
    }

}
int main()
{
    int n, a=0,nodVar=1,nokVar=0;
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        cin >> a;
        if (i == 0)
        {
            nokVar = a;
            nodVar = a;
        }
        nod(a, nodVar);
        nok(a, nokVar);
    }
    cout << "Nod = " << nodVar<<endl;
    cout << "Nok = " << nokVar;
}