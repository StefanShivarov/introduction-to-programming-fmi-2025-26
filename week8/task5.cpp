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
    int sums[10000];
    int pos = 0;
    for (int i = 0; i < n - p + 1; i++)
        for (int j = 0; j < m - q + 1; j++) {
            int sum = 0;
            for (int k = i; k < p + i; k++)
                for (int l = j; l < q + j; l++)
                    sum += matrix[k][l];
            sums[pos++] = sum;
        }
    int max = INT_MIN;
    for (int i = 0; i < pos; i++)
        max = max < sums[i] ? sums[i] : max;
    cout << max;
}