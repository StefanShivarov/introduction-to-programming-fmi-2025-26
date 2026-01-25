#include <iostream>
using namespace std;

constexpr size_t MAX_SIZE = 1024;
size_t strlen(const char arr[]) {
    size_t counter = 0;
    while (arr[counter++]);
    return counter - 1;
}
void shiftToRight(char arr[], const int beg) {
    const size_t size = strlen(arr);
    for (size_t i = size; i > beg; i--)
        arr[i] = arr[i - 1];
    arr[size + 1] = '\0';
}
char* newArray(char str[], const int arr[], const int n, const char ch) {
    for (int i = 0; i < n; i++)
        shiftToRight(str, arr[i]), str[arr[i] + i] = ch;
    const size_t size = strlen(str);
    char* arr1 = new char[size + 1];
    for (size_t i = 0; i < size; i++)
        arr1[i] = str[i];
    arr1[size] = '\0';
    return arr1;

}
int main() {
    char str[MAX_SIZE];
    cin.getline(str, MAX_SIZE);
    int arr[MAX_SIZE];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    char ch;
    cin >> ch;
    const char* arr1 = newArray(str, arr, n, ch);
    cout << arr1;
    delete[] arr1;
}
