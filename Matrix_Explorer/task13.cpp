#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    a += b;
    b = a - b;
    a -= b;
}
void selectionSort(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        if (i != minIndex)
            swap(arr[i], arr[minIndex]);
    }
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
    int arr[2500];
    int pos = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            arr[pos++] = matrix[i][j];
    pos = 0;
    selectionSort(arr, n * m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] = arr[pos++];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}