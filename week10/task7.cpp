#include <iostream>
using namespace std;

constexpr int MAX = 100;
size_t strlen(const char str[]) {
    int length = 0;
    while (str[length++] != '\0');
    return length - 1;
}
void strcpy(char dest[], char src[]) {
    for (int i = 0; i < strlen(src); i++)
        dest[i] = src[i];
    dest[strlen(src)] = '\0';
}
void strcat(char str[], char str1[]) {
    const size_t len = strlen(str), len1 = strlen(str1);
    for (int i = 0; i < len1; i++)
        str[len + i] = str1[i];
    str[len + len1] = '\0';
}
int strcmp(char str[], char str1[]) {
    const size_t min = strlen(str) < strlen(str1) ? strlen(str) : strlen(str1);
    for (int i = 0; i < min; i++)
        if (str[i] < str1[i])
            return -1;
        else if (str[i] > str1[i])
            return 1;
    if (strlen(str) < strlen(str1))
        return -1;
    else if (strlen(str) > strlen(str1))
        return 1;
    else
        return 0;
}
int main() {
    char src[MAX];
    char src1[MAX];
    cout << "Enter string to copy: ";
    cin >> src1;
    strcpy(src, src1);
    cout << "Copied string: " << src << endl;

    cout << "Enter string 1 to concatenate: ";
    cin >> src;
    cout << "Enter string 2 to concatenate: ";
    cin >> src1;
    strcat(src, src1);
    cout << "Concatenated string: " << src << endl;

    cout << "Enter string to check it's length: ";
    cin >> src;
    cout << "Length of string: " << strlen(src) << endl;

    cout << "Enter string 1 to compare: ";
    cin >> src;
    cout << "Enter string 2 to compare: ";
    cin >> src1;
    cout << "Comparison of strings: " << strcmp(src, src1) << endl;
}