#include <iostream>
using namespace std;

constexpr int MAX = 100;
constexpr int ascii_table_size = 256;
size_t strlen(const char str[]) {
    int length = 0;
    while (str[length++] != '\0');
    return length - 1;
}
bool isLowerCase(const char ch) {
    return ch >= 'a' && ch <= 'z';
}
bool isValid(const char str[]) {
    for (int i = 0; i < strlen(str); i++)
        if (!isLowerCase(str[i]))
            return false;
    return true;
}
void shiftBack(char str[], const int beg) {
    for (int i = beg; i < strlen(str) - 1; i++)
        str[i] = str[i + 1];
    str[strlen(str) - 1] = '\0';
}
void distinct(char str[]) {
    if (!isValid(str)) {
        cout << "Invalid input";
        return;
    }
    bool found[ascii_table_size] = {false};
    for (int i = 0; i < strlen(str); i++)
        if (found[str[i]])
            shiftBack(str, i), i--;
        else
            found[str[i]] = true;
}
int main() {
    char str[MAX];
    cin >> str;
    distinct(str);
    cout << str;
}