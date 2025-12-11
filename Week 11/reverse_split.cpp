#include <iostream>

// Split the string into groups of 5 chars and reverse each group in place.

int my_strlen(const char* s) {
    int len = 0;

    while (s[len] != '\0') {
        len++;
    }

    return len;
}

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

void reverseString(char* str, int start, int end) {
    int i = start;
    int j = end;

    while (i < j) {
        swap(str[i], str[j]);

        i++;
        j--;
    }
}

char* transformString(char* str) {
    if (str == nullptr) {
        return nullptr;
    }

    int n = my_strlen(str);
    const int k = 5; 

    for (int start = 0; start < n; start += k) {
        int end = start + k - 1;

        if (end >= n) {
            end = n - 1; 
        }

        reverseString(str, start, end);
    }

    return str;
}

int main() {
    char s1[] = "ABCDEFGHIJKL";
    std::cout << "Before: " << s1 << "\n";
    transformString(s1);
    std::cout << "After : " << s1 << "\n"; 

    char s2[] = "HelloWorld!";
    std::cout << "Before: " << s2 << "\n";
    transformString(s2);
    std::cout << "After : " << s2 << "\n";

    return 0;
}
