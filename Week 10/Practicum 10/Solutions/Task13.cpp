#include <iostream>
using namespace std;

void removeDuplicates(char* s) {
    bool seen[26] = {false};
    int counter = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';
        if (!seen[index]) {
            seen[index] = true;
            s[counter++] = s[i];
        }
    }
    s[counter] = '\0';
}

int main() {
    char s[256];
    cin.getline(s, 256);
    removeDuplicates(s);
    cout << s;
}
