#include <iostream>
using namespace std;

int sum(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main() {
    int num;
    cin >> num;
    while (num > 9)
        num = sum(num);
    cout << num;

}