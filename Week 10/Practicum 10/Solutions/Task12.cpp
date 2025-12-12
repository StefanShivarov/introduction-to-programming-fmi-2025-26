#include <iostream>
using namespace std;

void longestCommonPrefix(const char* s1, const char* s2, const char* s3, char* result) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s3[i] != '\0') {
        if (s1[i] == s2[i] && s2[i] == s3[i]) {
            result[i] = s1[i];
        } else {
            break;
        }
        i++;
    }
    result[i] = '\0';
}

int main() {
    char s1[256], s2[256], s3[256], prefix[256];

    cin.getline(s1, 256);
    cin.getline(s2, 256);
    cin.getline(s3, 256);

    longestCommonPrefix(s1, s2, s3, prefix);

    cout << prefix;
}
