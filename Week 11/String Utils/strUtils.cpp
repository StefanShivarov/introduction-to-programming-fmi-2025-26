#include <iostream>
using namespace std;

unsigned myStrlen(const char* str) {
    int counter = 0;
    while (str[counter] != '\0') {
        counter++;
    }
    return counter;
}

void myStrcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int myStrcmp(const char* a, const char* b) {
    // if myStrcmp(a, b) == 0 , then a and b are equal
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return (unsigned char)a[i] - (unsigned char)b[i];
        }
        i++;
    }
    return (unsigned char)a[i] - (unsigned char)b[i];
}

void myStrcat(char* dest, const char* src) {
    // make sure that dest has enough capacity allocated to hold the concatenated result
    unsigned len = myStrlen(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[len++] = src[i];
        i++;
    }
    dest[len] = '\0';
}

int main() {
    char first[256];
    cin >> first;

    cout << myStrlen(first) << endl;
    
    char second[256];
    myStrcpy(second, first);

    cout << second << endl;

    myStrcat(second, first);
    cout << second << endl;
}
