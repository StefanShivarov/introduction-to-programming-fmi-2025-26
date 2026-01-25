#include <iostream>
using namespace std;

bool contains(const unsigned n, const int k) {
    if (n % 10 == k) {
        return true;
    }
    if (n == 0) {
        return false;
    }
    return contains(n / 10, k);
}
int main() {
    unsigned n;
    int k;
    cin >> n >> k;
    if (contains(n, k)) {
        cout << "true";
    }
    else {
        cout << "false";
    }
}