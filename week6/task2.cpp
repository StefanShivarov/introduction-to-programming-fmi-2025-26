#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool decreasing = true;
    for (int i = 1; i < n; i++)
        if (a[i - 1] < a[i]) {
            decreasing = false;
            break;
        }
    if (decreasing)
        cout << "Тhe series is monotonically decreasing.";
    else
        cout << "Тhe series is not monotonically decreasing.";
}