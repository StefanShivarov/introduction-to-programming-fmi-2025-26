#include <iostream>
#include <cmath>
using namespace std;

int getWindowBase(int M) {
    int base = 1;

    for (int i = 1; i < M; i++) {
        base *= 10;
    }
        
    return base;
}


int main() {
    int N;
    cin >> N;

    int arr[1000];
    for (int i = 0; i < N; i++) cin >> arr[i];

    int M, K;
    cin >> M >> K;

    int current = 0;
    int best = 0;
    int bestDiff = 1000000000;

    int base = getWindowBase(M);

    for (int i = 0; i < N; i++) {

        if (i < M) {
            current = current * 10 + arr[i];

            if (i == M - 1) {
                best = current;
                bestDiff = abs(current - K);
            }
        }
        else {
            current -= arr[i - M] * base;

            current = current * 10 + arr[i];

            int diff = abs(current - K);
            if (diff < bestDiff) {
                bestDiff = diff;
                best = current;
            }
        }
    }

    cout << best;
    return 0;
}
