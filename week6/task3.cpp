#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int c0 = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0, c9 = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        if (a[i] == 0)
            c0++;
        else if (a[i] == 1)
            c1++;
        else if (a[i] == 2)
            c2++;
        else if (a[i] == 3)
            c3++;
        else if (a[i] == 4)
            c4++;
        else if (a[i] == 5)
            c5++;
        else if (a[i] == 6)
            c6++;
        else if (a[i] == 7)
            c7++;
        else if (a[i] == 8)
            c8++;
        else
            c9++;
    if (c1 < 2 && c2 < 2 && c3 < 2 && c4 < 2 && c5 < 2 && c6 < 2 && c7 < 2 && c8 < 2 && c9 < 2)
        cout << "Yes, the sequence consists of distinct elements.";
    else
        cout << "No, the sequence does not consist of distinct elements.";
}