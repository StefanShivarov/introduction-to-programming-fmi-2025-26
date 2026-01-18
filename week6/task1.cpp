#include <iostream>
using namespace std;

double sum(int a[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum / n;
}
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << sum(a, n);
}