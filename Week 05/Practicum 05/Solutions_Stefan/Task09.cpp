#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int lcm(int a, int b) {
    int greater = max(a, b);
    int smaller = min(a, b);

    for (int i = greater; i <= a * b; i += greater) {
        if (i % smaller == 0) {
            return i;
        }
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << lcm(a, b) << endl;
}
