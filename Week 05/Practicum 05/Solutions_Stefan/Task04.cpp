#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int absoluteValue(int number) {
    return number < 0 ? -number : number;
}

int main() {
    int n;
    cin >> n;
    cout << absoluteValue(n) << endl;
}
