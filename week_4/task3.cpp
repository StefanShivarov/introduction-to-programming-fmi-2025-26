#include <iostream>
using namespace std;

int askUser(const int from, const int to) {
    int n;
    do
        cin >> n;
    while (n < from || n > to);
    return n;
}
int main() {
    int a, b;
    cout << "Enter borders: ";
    cin >> a >> b;
    cout << "Enter a number: ";
    int result = askUser(a, b);
    cout << "The entered number is: " << result;
}