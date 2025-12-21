#include <iostream>
using namespace std;

constexpr size_t MAX_SIZE = 1024;
size_t strlen(const char arr[]) {
    size_t counter = 0;
    while (arr[counter++]);
    return counter - 1;
}
bool isLowerCaseLetter(const char ch) {
    return ch >= 'a' && ch <= 'z';
}
bool isUpperCaseLetter(const char ch) {
    return ch >= 'A' && ch <= 'Z';
}
char* func() {
    char arr1[MAX_SIZE];
    char arr2[MAX_SIZE];
    cin.getline(arr1, MAX_SIZE);
    cin.getline(arr2, MAX_SIZE);
    size_t counter = 0;
    for (int i = 0; arr1[i]; i++)
        if (isLowerCaseLetter(arr1[i]))
            counter++;
    for (int i = 0; arr2[i]; i++)
        if (isUpperCaseLetter(arr2[i]))
            counter++;
    char* arr3 = new char[counter + 1];
    int pos = 0;
    for (int i = 0; arr1[i]; i++)
        if (isLowerCaseLetter(arr1[i]))
            arr3[pos++] = arr1[i];
    for (int i = 0; arr2[i]; i++)
        if (isUpperCaseLetter(arr2[i]))
            arr3[pos++] = arr2[i];
    arr3[pos] = '\0';
    return arr3;
}
int main() {
    const char* arr = func();
    cout << arr;
    delete[] arr;
}