#include <iostream>
using namespace std;

int length(long num) {
    int counter = 0;
    while (num)
        num /= 10, counter++;
    return counter;
}
void swap(int &a, int &b) {
    const int temp = a;
    a = b;
    b = temp;
}
long* func(long num, const int n, const int m) {
    const int numLength = length(num);
    long* result = new long[numLength];
    for (int i = numLength - 1; i >= 0; i--)
        result[i] = num % 10, num /= 10;
    swap(result[n - 1], result[m - 1]);
    return result;
}
int main() {
    long num;
    int n, m;
    cin >> num >> n >> m;
    const long* result = func(num, n, m);
    const int len = length(num);
    for (int i = 0; i < len; i++)
        if (i != len - 1)
            cout << result[i] << ", ";
        else
            cout << result[i];
    delete[] result;
}