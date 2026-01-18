#include <iostream>
using namespace std;

constexpr int MAX = 100;
size_t strlen(const char str[]) {
    int length = 0;
    while (str[length++] != '\0');
    return length - 1;
}
bool isLowerCase(char ch) {
    return ch >= 'a' && ch <= 'z';
}
void extractLowerCaseLetters(char str1[], char str2[]) {
    int counter = 0;
    for (int i = 0; i < strlen(str1); i++)
        if (isLowerCase(str1[i]))
            str2[counter++] = str1[i];
    str2[counter] = '\0';
}
int main() {
    char str1[MAX], str2[MAX];
    cin >> str1;
    extractLowerCaseLetters(str1, str2);
    cout << str2;
}