#include <iostream>
using namespace std;

void spiralFromCenter(int matrix[100][100], int n) {
    int total = n * n;
    int count = 0;
    int row = n / 2;
    int col = n / 2;
    if (n % 2 == 0)
        row = n / 2, col = n / 2;
    cout << matrix[row][col] << " ";
    count++;
    int step = 1;
    int dir = 0;
    while (count < total)
        for (int d = 0; d < 4; d++) {
            for (int s = 0; s < step; s++) {
                if (dir == 0)
                    col--;
                else if (dir == 1)
                    row--;
                else if (dir == 2)
                    col++;
                else if (dir == 3)
                    row++;
                if (row >= 0 && row < n && col >= 0 && col < n) {
                    cout << matrix[row][col] << " ";
                    count++;
                    if (count >= total)
                        return;
                }
            }
            dir = (dir + 1) % 4;
            if (d % 2)
                step++;
        }
}
int main() {
    int n;
    cin >> n;
    int matrix[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    spiralFromCenter(matrix, n);
//решението е от изкуствен интелект, не успях да я реша
}
