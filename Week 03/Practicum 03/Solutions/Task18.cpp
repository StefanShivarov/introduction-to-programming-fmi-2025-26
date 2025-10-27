#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    int n;
    cin >> n;
    int totalRows = 2 * n - 1;

    for (int i = 0; i < totalRows; i++) {
        int maxNumInRow = (i < n) ? i + 1 : 2 * n - i - 1;
        for (int j = 1; j <= maxNumInRow; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}
