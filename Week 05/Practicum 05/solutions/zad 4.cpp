using namespace std;    

#include <iostream>


unsigned int absoluteValue(int number)
{
    return ((number < 0) ? -number : number);
}
int main()
{
    int a;
    cin >> a;
	cout << absoluteValue(a);

}

