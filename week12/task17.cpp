#include <iostream>
using namespace std;

constexpr size_t MAX_SIZE = 1024;
size_t strlen(const char arr[]) {
    size_t counter = 0;
    while (arr[counter++]);
    return counter - 1;
}
char* firstWord(const char arr[]) {
    const size_t len = strlen(arr);
    size_t firstIndex = 0;
    for (size_t i = 0; i < len; i++)
        if (arr[i] == ' ') {
            firstIndex = i;
            break;
        }
    char* first = new char[firstIndex + 1];
    for (size_t i = 0; i < firstIndex; i++)
        first[i] = arr[i];
    first[firstIndex] = '\0';
    return first;
}
char* lastWord(const char arr[]) {
    const size_t len = strlen(arr);
    size_t lastIndex = 0;
    for (size_t i = 0; i < len; i++)
        if (arr[i] == ' ')
            lastIndex = i;
    lastIndex++;
    char* last = new char[len - lastIndex + 1];
    for (size_t i = lastIndex; i < len; i++)
        last[i - lastIndex] = arr[i];
    last[len - lastIndex] = '\0';
    return last;
}
int main() {
    char arr[MAX_SIZE];
    cin.getline(arr, MAX_SIZE);
    const char* first = firstWord(arr);
    const char* last = lastWord(arr);
    const size_t len1 = strlen(first), len2 = strlen(last);
    char* firstAndLast = new char[len1 + 1 + len2 + 1];
    for (size_t i = 0; i < len1; i++)
        firstAndLast[i] = first[i];
    firstAndLast[len1] = ' ';
    for (size_t i = len1 + 1; i < len1 + 1 + len2; i++)
        firstAndLast[i] = last[i - len1 - 1];
    firstAndLast[len1 + 1 + len2] = '\0';
    cout << firstAndLast << endl;
    delete[] first;
    delete[] last;
    delete[] firstAndLast;
}
