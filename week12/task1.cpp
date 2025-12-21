#include <iostream>
using namespace std;

constexpr size_t MAX_SIZE = 1024;
size_t strlen(const char arr[]) {
    size_t counter = 0;
    while (arr[counter++]);
    return counter - 1;
}
void strcat(const char arr1[], const char arr2[], char arr3[]) {
    const size_t len = strlen(arr1), len1 = strlen(arr2);
    for (size_t i = 0; i < len; i++)
        arr3[i] = arr1[i];
    for (size_t i = len; i < len + len1; i++)
        arr3[i] = arr2[i - len];
    arr3[len + len1] = '\0';
}
char* func() {
    char arr1[MAX_SIZE];
    char arr2[MAX_SIZE];
    cin.getline(arr1, MAX_SIZE);
    cin.getline(arr2, MAX_SIZE);
    char* arr3 = new char[strlen(arr1) + strlen(arr2) + 1];
    strcat(arr1, arr2, arr3);
    return arr3;
}
int main() {
    const char* arr = func();
    cout << arr << endl;
    delete[] arr;
}