#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    int n;
    cin >> n;

    int result = 1; // всяко число си е делител само на себе си, така че винаги има поне 1
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            result++;
        }
    }

    cout << result << endl;
}
