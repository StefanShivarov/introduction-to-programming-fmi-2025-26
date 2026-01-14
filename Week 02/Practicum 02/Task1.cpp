#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    int n;
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++){
        cin >> temp;
        sum += temp;
    }
    cout << sum << endl;
}