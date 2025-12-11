#include <iostream>

int my_strlen(const char* s) {
    int len = 0;

    while (s[len] != '\0') {
        len++;
    }

    return len;
}

char* my_strcpy(char* dest, const char* src) {
    char* start = dest;

    while (*src != '\0') {
        *dest = *src;   
        dest++;        
        src++;
    }

    *dest = '\0';
    return start;
}

char* my_strcat(char* dest, const char* src) {
    char* start = dest;

    while (*dest) {       
        dest++;
    }

    while (*src) {         
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';          
    return start;
}

int my_strcmp(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }

    return (unsigned char)*s1 - (unsigned char)*s2;
}

int main()
{
    char a[] = "Hello";
    char b[] = "World";

    std::cout << my_strlen(a) << "\n";      // 5
    my_strcat(a, b);
    std::cout << a << "\n";                 // HelloWorld

    my_strcpy(a, "Test");
    std::cout << a << "\n";                 // Test

    std::cout << my_strcmp("abc", "abd");   // negative value

    return 0;
}
