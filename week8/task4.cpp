#include <iostream>
using namespace std;

int main() {
    int matrix[100][100];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    int p, q;
    cin >> p >> q;
    for (int i = 0; i < n - p + 1; i++)
        for (int j = 0; j < m - q + 1; j++) {
            for (int k = i; k < p + i; k++) {
                for (int l = j; l < q + j; l++)
                    cout << matrix[k][l] << " ";
                cout << endl;
            }
            cout << endl;
        }
}