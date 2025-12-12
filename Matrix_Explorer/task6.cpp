#include <iostream>
using namespace std;

bool isPalindrome(char array[10], int n) {
    for (int i = 0; i < n / 2; i++)
        if (array[i] != array[n - i - 1])
            return false;
    return true;
}
int main() {
    char matrix[10][10];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    for (int i = 0; i < n; i++) {
        char array[10];
        for (int j = 0; j < n; j++)
            array[j] = matrix[i][j];
        if (!isPalindrome(array, n)) {
            cout << "not magic palindrome";
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        char array[10];
        for (int j = 0; j < n; j++)
            array[j] = matrix[j][i];
        if (!isPalindrome(array, n)) {
            cout << "not magic palindrome";
            return 0;
        }
    }
    char array[10];
    for (int i = 0; i < n; i++)
        array[i] = matrix[i][i];
    if (!isPalindrome(array, n)) {
        cout << "not magic palindrome";
        return 0;
    }
    char array1[10];
    for (int i = 0; i < n; i++)
        array1[i] = matrix[i][n - i - 1];
    if (!isPalindrome(array1, n))
        cout << "not magic palindrome";
    else
        cout << "magic palindrome";
}