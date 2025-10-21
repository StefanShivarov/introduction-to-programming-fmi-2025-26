#include <iostream>
#include <cmath>

using namespace std;

int main() {
    unsigned int n = 0, k = 0, sum = 0;

    cout << "N: ";
    cin >> n;
    
    cout << "K: "; 
    cin >> k;

    for (int i = 1; i <= n; ++i) {
        unsigned int num = 0;

        for (int j = 0; j < i; ++j) {
            num += pow(10, j) * k;
        }

        sum += num;
    }

    cout << "The sum is: " << sum << endl;

    return 0;
}