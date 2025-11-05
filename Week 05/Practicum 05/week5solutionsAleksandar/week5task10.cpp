#include <iostream>
#include <cmath>
using namespace std;

void gcd(int a[], int b) {
    int min = 1000000000;
    int gcdresult = 0;
    for (int i = 0; i < b; i++)
    {
        if (a[i] < min) { min = a[i]; }
    }
    for (int i = 1; i<=min; i++)
    {
        int k = 0;
        for (int j = 0; j < b; j++)
        {
            if (a[j]%i==0) { k++; }
        }
        if (k == b) { gcdresult = i; }
    }
    cout << "GCD: " << gcdresult << endl;
}

void lcm(int a[], int b) {
    for (int i = 1; ; i++)
    {
        int k = 0;
        for (int j = 0; j < b; j++)
        {
            if (i % a[j] == 0) { k++; }
        }
        if (k == b) { cout << "LCM: " << i; break; }
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    gcd(arr, n);
    lcm(arr, n);
}