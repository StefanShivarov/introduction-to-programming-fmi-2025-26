#include <iostream>
using namespace std;

int pow(int base, int power) {
    int result = 1;
    for (int i = 1; i <= power; i++)
        result *= base;
    return result;
}
void divideNInto2Pieces(int n, int& left, int& right) {
    int copyOfN = n;
    int counter = 0;
    while (copyOfN) {
        copyOfN /= 10;
        counter++;
    }
    counter /= 2;
    for (int i = 0; i < counter; i++) {
        right += pow(10, i) * (n % 10);
        n /= 10;
    }
    left = n;
}
int main() {
    int n;
    int left = 0, right = 0;
    cin >> n;
    divideNInto2Pieces(n, left, right);
    cout << "left = " << left << ", right = " << right << endl;
}