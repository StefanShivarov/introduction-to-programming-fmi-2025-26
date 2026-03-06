#include <iostream>
using namespace std;

bool isSquareRoot(int n) {
    for (int i = 1; i <= n; i++)
        if (i * i == n)
            return true;
    return false;
}
int main() {
    int n;
    cin >> n;
    if (isSquareRoot(n))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}