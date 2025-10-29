#include <iostream>
using namespace std;

int mergeNumbers(int n, int k) {
    int digitsK = 0;
    int tempK = k;
    while (tempK > 0) {
        digitsK++;
        tempK /= 10;
    } 
    int multi = 1;
    while (digitsK > 0) { multi *= 10; digitsK--; }
    k += n*multi;
    return k;
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << mergeNumbers(n, k);
}