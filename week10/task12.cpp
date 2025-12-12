#include <iostream>
using namespace std;

constexpr int MAX = 100;
size_t strlen(const char str[]) {
    int length = 0;
    while (str[length++] != '\0');
    return length - 1;
}
void longestPrefix(char str1[], const char str2[], char str3[]) {
    size_t min = strlen(str1) < strlen(str2) ? strlen(str1) : strlen(str2);
    min = min < strlen(str3) ? min : strlen(str3);
    for (int i = 0; i < min; i++)
        if (str1[i] != str2[i] || str2[i] != str3[i])
            str1[i] = '\0';
}
int main() {
    char str1[MAX], str2[MAX], str3[MAX];
    cin.getline(str1, MAX);
    cin.getline(str2, MAX);
    cin.getline(str3, MAX);
    longestPrefix(str1, str2, str3);
    cout << str1;
}