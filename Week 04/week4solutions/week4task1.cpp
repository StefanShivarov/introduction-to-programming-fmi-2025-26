#include <iostream>
using namespace std;

int action(int a, int b, char c) {
    switch (c) {
    case '+': return a + b; break;
    case '-': return a - b; break;
    case '*': return a * b; break;
    case '/': return a / b; break;
    }
}
int main()
{
    int a, b;
    char c;
    cin >> a >> b >> c;
    cout << action(a, b, c);
}
