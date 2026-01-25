#include <iostream>
using namespace std;

constexpr size_t MAX_SIZE = 1024;
size_t strlen(const char arr[]) {
    size_t counter = 0;
    while (arr[counter++]);
    return counter - 1;
}
char* func(char str[], char temp[]) {
    const size_t lenStr = strlen(str);
    const size_t lenTemp = strlen(temp) / 2;
    for (size_t i = 0; i < lenStr; i++)
        for (size_t j = 0; j < lenTemp; j++)
            if (str[i] == temp[j]) {
                str[i] = temp[j + lenTemp + 1];
                break;
            }
    char* result = new char[lenStr + 1];
    for (int i = 0; i < lenStr; i++)
        result[i] = str[i];
    result[lenStr] = '\0';
    return result;
}
int main() {
    char str[MAX_SIZE];
    cin.getline(str, MAX_SIZE);
    char temp[MAX_SIZE];
    cin.getline(temp, MAX_SIZE);
    const char* result = func(str, temp);
    cout << result << endl;
    delete[] result;
}