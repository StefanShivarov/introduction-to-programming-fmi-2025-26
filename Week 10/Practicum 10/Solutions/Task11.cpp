#include <iostream>
using namespace std;

void replaceOccurrences(char* str, char x, char a, char b) {
    int occurencesCount = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == x) {
            occurencesCount++;
            if (occurencesCount % 2 == 0) {
                str[i] = a;
            } else {
                str[i] = b;
            }
        }
    }
}

int main() {
    char s[256];
    char x, a, b;

    cin.getline(s, 256);
    cin >> x >> a >> b;
    replaceOccurrences(s, x, a, b);

    cout << s;
}
