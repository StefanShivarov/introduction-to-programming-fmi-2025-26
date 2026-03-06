#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void sort3(int& min, int& mid, int& max) {
    while (min > mid || mid > max)
        if (min > mid)
            swap(min, mid);
        else if (mid > max)
            swap(mid, max);
}
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    sort3(a, b, c);
    cout << a << " " << b << " " << c << endl;
}