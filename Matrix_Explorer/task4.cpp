#include <iostream>
using namespace std;

int main() {
    int n, m, p, q;
    cout << "N: ";
    cin >> n;
    cout << "M: ";
    cin >> m;
    int matrix1[10][10];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix1[i][j];
    cout << "P: ";
    cin >> p;
    cout << "Q: ";
    cin >> q;
    int matrix2[10][10];
    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++)
            cin >> matrix2[i][j];
    if (m != p) {
        cout << "Matrix multiplication is not possible.";
        return 0;
    }
    int matrix3[10][10];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < q; j++) {
            int sum = 0;
            for (int k = 0; k < m; k++)
                sum += matrix1[i][k] * matrix2[k][j];
            matrix3[i][j] = sum;
        }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++)
            cout << matrix3[i][j] << " ";
        cout << endl;
    }
}