#include <iostream>
using namespace std;

constexpr int MAX = 100;
size_t strlen(const char str[]) {
    int length = 0;
    while (str[length++] != '\0');
    return length - 1;
}
void substring(char str[], const int beg, const int end) {
    if (end > strlen(str)) {
        if (beg >= strlen(str))
            str[0] = '\0';
        else {
            for (int i = beg; i < strlen(str); i++)
                str[i - beg] = str[i];
            str[strlen(str) - beg] = '\0';
        }
    }
    else {
        for (int i = beg; i <= end; i++)
            str[i - beg] = str[i];
        str[end - beg + 1] = '\0';
    }
}
int main() {
    char str[MAX];
    int beg, end;
    cin >> str >> beg >> end;
    substring(str, beg, end);
    cout << str << endl;
}