#include <iostream>
using namespace std;

constexpr int MAX = 100;
size_t strlen(const char str[]) {
    int length = 0;
    while (str[length++] != '\0');
    return length - 1;
}
char otherCase(const char ch) {
    if (ch >= 'A' && ch <= 'Z')
        return ch - 'A' + 'a';
    else
        return ch - 'a' + 'A';
}
void censor(char str[], char substr[]) {
    for (int i = 0; i < strlen(str) - strlen(substr); i++) {
        bool same = true;
        for (int j = i; j < strlen(substr) + i; j++)
            if (str[j] != substr[j - i] && str[j] != otherCase(substr[j - i]))
                same = false;
        if (same)
            for (int j = i; j < strlen(substr) + i; j++)
                str[j] = '*';
    }
}
int main() {
    char str[MAX], substr[MAX];
    cin.getline(str, MAX);
    cin.getline(substr, MAX);
    censor(str, substr);
    cout << str;
}