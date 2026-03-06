#include <iostream>
using namespace std;

constexpr int ascii_table_size = 256;
size_t strlen(const char str[]) {
    int length = 0;
    while (str[length++] != '\0');
    return length - 1;
}
int analyzeArr(const char *str) {
    if (str == nullptr)
        return -1;
    int counter = 0;
    bool found[ascii_table_size] = {false};
    for (int i = 0; i < strlen(str); i++)
        found[str[i]] = true;
    for (int i = 0; i < ascii_table_size; i++)
        if (found[i])
            counter++;
    return counter;
}
int main() {
    char str[1024];
    cin >> str;
    cout << analyzeArr(str);
}