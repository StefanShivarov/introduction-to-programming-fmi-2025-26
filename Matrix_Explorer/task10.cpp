#include <iostream>
using namespace std;

bool isAscending(int array[], int n) {
    for (int i = 1; i < n; i++)
        if (array[i - 1] > array[i])
            return false;
    return true;
}
int main() {
    int matrix[50][50];
    int n;
    cin >> n;
    int m;
    cin >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    for (int i = 0; i < n; i++) {
        int counter = 0;
        int temp = i;
        int array[50];
        for (int j = 0; j < m && temp >= 0; j++, temp--)
            array[counter++] = matrix[temp][j];
        if (!isAscending(array, counter)) {
            cout << "false";
            return 0;
        }
    }
    for (int j = 1; j < m; ++j) {
        int row = n - 1;
        int col = j;
        int counter = 0;
        int array[50];
        while (row >= 0 && col < m)
            array[counter++] = matrix[row--][col++];
        if (!isAscending(array, counter)) {
            cout << "false";
            return 0;
        }
    }
    cout << "true";
}