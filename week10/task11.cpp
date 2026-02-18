#include <iostream>
using namespace std;

constexpr int MAX = 100;
size_t strlen(const char str[]) {
    int length = 0;
    while (str[length++] != '\0');
    return length - 1;
}
void transform(char str[], const char x, const char a, const char b) {
int counter = 0;
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == x)
            if (counter++ % 2)
                str[i] = b;
            else
                str[i] = a;
}
int main() {
    char str[MAX];
    cin.getline(str, MAX);
    char x, a, b;
    cin >> x >> a >> b;
    transform(str, x, a, b);
    cout << str << endl;
}
