#include <iostream>
using namespace std;

constexpr size_t MAX_SIZE = 1024;
bool isLetter(const char ch) {
    return ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z';
}
char* func(const int arr1[], const int arr2[], const int n) {
    int counter = 0;
    for (int i = 0; i < n; i++)
        if (isLetter(arr1[i] + arr2[i]))
            counter++;
    char* result = new char[counter + 1];
    counter = 0;
    for (int i = 0; i < n; i++)
        if (isLetter(arr1[i] + arr2[i]))
            result[counter++] = arr1[i] + arr2[i];
    result[counter] = '\0';
    return result;
}
int main() {
    int arr1[MAX_SIZE];
    int arr2[MAX_SIZE];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    for (int i = 0; i < n; i++)
        cin >> arr2[i];
    const char* result = func(arr1, arr2, n);
    cout << result << endl;
    delete[] result;
}