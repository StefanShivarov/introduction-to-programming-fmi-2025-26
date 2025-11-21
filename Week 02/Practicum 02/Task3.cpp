#include <iostream>
using namespace std;

int main() {
    int temp;
    cin >> temp;
    int fact = 1;
    for (int i = temp; i >= 1; i--)
        fact *= i;
    cout << fact << endl;
}