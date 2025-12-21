#include <iostream>
using namespace std;

constexpr size_t MAX_SIZE = 1024;
constexpr size_t ascii_table_size = 256;
size_t strlen(const char arr[]) {
    size_t counter = 0;
    while (arr[counter++]);
    return counter - 1;
}
char* func() {
    int counter = 0;
    char arr[MAX_SIZE];
    cin.getline(arr, MAX_SIZE);
    bool ascii[ascii_table_size] = { false };
    const size_t n = strlen(arr);
    for (size_t i = 0; i < n; i++)
        if (!ascii[arr[i]])
            ascii[arr[i]] = true;
    for (size_t i = 0; i < ascii_table_size; i++)
        if (ascii[i])
            ascii[i] = false, counter++;
    char* arr1 = new char[counter + 1];
    counter = 0;
    for (size_t i = 0; i < n; i++)
        if (!ascii[arr[i]])
            arr1[counter++] = arr[i], ascii[arr[i]] = true;
    arr1[counter] = '\0';
    return arr1;
}
int main() {
    const char* arr = func();
    cout << arr;
    delete[] arr;
}