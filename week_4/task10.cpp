#include <iostream>
using namespace std;

int smallestN(int n) {
    int num = 0;
    int temp = 0;
    for (int i = 1; i <= 9; i++) {
        int copyOfN = n;
        while (copyOfN) {
            if (i == copyOfN % 10)
                num = num * 10 + i;
            copyOfN /= 10;
        }
    }
    return num;
}
int main() {
    cout << "Въведете число: ";
    int n;
    cin >> n;
    cout << smallestN(n);
}