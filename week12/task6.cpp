#include <iostream>
using namespace std;

constexpr size_t MAX_SIZE = 1024;
char* func(const char arr1[], const char arr2[]) {
    int counter = 0;
    while (arr1[counter] == arr2[counter] && arr1[counter] != '\0')
        counter++;
    char* result = new char[counter + 1];
    for (int i = 0; i < counter; i++)
        result[i] = arr1[i];
    result[counter] = '\0';
    return result;
}
int main() {
    char arr1[MAX_SIZE];
    char arr2[MAX_SIZE];
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
        cin >> arr1[i];
    arr1[n] = '\0';
    for (size_t i = 0; i < n; i++)
        cin >> arr2[i];
    arr2[n] = '\0';
    const char* result = func(arr1, arr2);
    cout << result << endl;
    delete[] result;
}