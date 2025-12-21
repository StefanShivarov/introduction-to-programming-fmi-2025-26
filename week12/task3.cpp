#include <iostream>
using namespace std;

constexpr size_t MAX_SIZE = 1024;
size_t strlen(const char arr[]) {
    size_t counter = 0;
    while (arr[counter++]);
    return counter - 1;
}
void swap(char& a, char& b) {
    const char temp = a;
    a = b;
    b = temp;
}
void reverse(char str[]) {
    const size_t n = strlen(str);
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
void my_strcpy(char dest[], const char src[]) {
    const size_t n = strlen(src);
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
    dest[n] = '\0';
}
char* func() {
    char str[MAX_SIZE];
    cin.getline(str, MAX_SIZE);
    char* str1 = new char[strlen(str) + 1];
    my_strcpy(str1, str);
    reverse(str1);
    return str1;
}
int main() {
    const char* arr = func();
    cout << arr;;
    delete[] arr;
}
