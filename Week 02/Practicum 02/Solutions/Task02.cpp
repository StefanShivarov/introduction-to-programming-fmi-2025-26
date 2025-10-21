#include <iostream>
using namespace std;

int main() {
    int a, max = 0;
    cin >> a;
    cin >> max;

    for (int i = 1; i < a; i++) {
        int k;
        cin >> k;
        if (k > max) {
            max = k;
        }
    }
    cout << max << endl;
    return 0;
}
