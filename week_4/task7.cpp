#include <iostream>
using namespace std;

char returnNum(char c) {
    return c >= '0' && c <= '9' ? c : - 1; // ?
}
int main() {
    char c;
    cin >> c;
    cout << returnNum(c);
}