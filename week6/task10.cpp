#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}
int compare(int a, int b) {
    int copyOfA = a, copyOfB = b, ca = 0, cb = 0;
    while (a)
        ca++, a /= 10;
    int a1[ca];
    for (int i = ca - 1; i >= 0; i--)
        a1[i] = copyOfA % 10, copyOfA /= 10;
    while (b)
        cb++, b /= 10;
    int b1[cb];
    for (int i = cb - 1; i >= 0; i--)
        b1[i] = copyOfB % 10, copyOfB /= 10;
    int min = ca < cb ? ca : cb;
    for (int i = 0; i < min; i++)
        if (a1[i] < b1[i])
            return -1;
        else if (a1[i] > b1[i])
            return 1;
    if (ca != cb)
        return ca > cb ? 1 : -1;
    return 0;
}
void sortLex(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
            if (compare(arr[j], arr[j + 1]) > 0) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        if (!swapped)
            break;
    }
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sortLex(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}