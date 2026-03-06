#include <iostream>
using namespace std;

bool linearDependent(int a[], int b[], int size) {
    double coef = 0;
    for (int i = 0; i < size; i++)
        if (a[i] != 0 && b[i] != 0) {
            coef = (double) a[i] / b[i];
            break;
        }
    for (int i = 0; i < size; i++)
        if (coef * b[i] != a[i])
            return false;
    return true;
}
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int b[n];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    if (linearDependent(a, b, n))
        cout << "Yes, the arrays are linearly dependent.";
    else
        cout << "No, the arrays are not linearly dependent.";
}