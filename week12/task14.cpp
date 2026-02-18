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
size_t getCountOfLowerCaseLetters(const char arr[]) {
    const size_t len = strlen(arr);
    size_t counter = 0;
    for (size_t i = 0; i < len; i++)
        if (isLowerCaseLetter(arr[i]))
            counter++;
    return counter;
}
size_t getCountOfUpperCaseLetters(const char arr[]) {
    const size_t len = strlen(arr);
    size_t counter = 0;
    for (size_t i = 0; i < len; i++)
        if (isUpperCaseLetter(arr[i]))
            counter++;
    return counter;
}
char* dynArray(char arr1[], char arr2[]) {
    const size_t len1 = strlen(arr1), len2 = strlen(arr2);
    size_t counter = getCountOfLowerCaseLetters(arr1) + getCountOfUpperCaseLetters(arr2);
    char* arr = new char[counter + 1];
    counter = 0;
    for (int i = 0; i < len1; i++)
        if (isLowerCaseLetter(arr1[i]))
            arr[counter++] = arr1[i];
    for (int i = 0; i < len2; i++)
        if (isUpperCaseLetter(arr2[i]))
            arr[counter++] = arr2[i];
    arr[counter] = '\0';
    return arr;
}
int main() {
    char arr1[MAX_SIZE], arr2[MAX_SIZE];
    cin >> arr1 >> arr2;
    const char* arr = dynArray(arr1, arr2);
    cout << arr;
    delete[] arr;
}