#include <iostream>
using namespace std;

const unsigned MAX_N = 51;
int cache[MAX_N];

long long fib(int n) {
    if (n == 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    if (cache[n] != -1) {
        cout << "Loading fib(" << n << ")  from cache..." << endl;
        return cache[n];
    }

    cout << "Calculating fib(" << n << ") recursively..." << endl;
    cache[n] = fib(n - 1) + fib(n - 2);
    return cache[n];
}

int main() {
    long long n;
    for (int i = 0; i <= MAX_N; i++) {
        cache[i] = -1;
    }

    cin >> n;
    cout << fib(n) << endl;
}
