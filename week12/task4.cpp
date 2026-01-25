#include <iostream>
using namespace std;

constexpr size_t MAX_SIZE = 1024;
int getLargest(const int arr1[], const int n, const int arr2[], const int m) {
    int largest = arr1[0];
    for (int i = 1; i < n; i++)
        if (arr1[i] > largest)
            largest = arr1[i];
    for (int i = 0; i < m; i++)
        if (arr2[i] > largest)
            largest = arr2[i];
    return largest;
}
int main() {
    int arr1[MAX_SIZE], arr2[MAX_SIZE];
    int k;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    for (int i = 0; i < m; i++)
        cin >> arr2[i];
    cin >> k;
    int len = getLargest(arr1, n, arr2, m) + 1;
    bool* met = new bool[len];
    for (int i = 0; i < len; i++)
        met[i] = false;
    for (int i = 0; i < n; i++)
        if (!(arr1[i] % k))
            met[arr1[i]] = true;
    for (int i = 0; i < m; i++)
        if (!(arr2[i] % k))
            met[arr2[i]] = true;
    int counter = 0;
    for (int i = 0; i < len; i++)
        if (met[i])
            counter++;
    int* divisableByK = new int[counter];
    counter = 0;
    for (int i = 0; i < len; i++)
        if (met[i])
            divisableByK[counter++] = i;
    for (int i = 0; i < counter; i++)
        cout << divisableByK[i] << " ";
    delete[] met;
    delete[] divisableByK;
}