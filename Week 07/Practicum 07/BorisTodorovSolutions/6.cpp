#include <iostream>
using std::cin;
using std::cout;
using std::endl;
const int MAX = 10;
bool isMainDiagonalPalindrome(char matrix[][MAX], int n)
{
    for (int i = 0;i < n;i++)
    {
        if (matrix[i][i] != matrix[n - i - 1][n-i-1])
        {
            return false;
        }
    }
    return true;
}
bool isSecondaryDiagonalPalindrome(char matrix[][MAX], int n)
{
    for (int i = n - 1, j = 0;i >= n/2-1;i--, j++)
    {
        if (matrix[i][j] != matrix[n - i - 1][n- j - 1])
        {
            return false;
        }
    }
    return true;
}
bool areColsPalindrome(char matrix[][MAX], int n)
{
    for (int i = 0;i < n/2;i++)
    {
        for (int j = 0;j < n;j++)
        {
            if (matrix[i][j] != matrix[n-i-1][j])
            {
                return false;
            }
        }
    }
    return true;
}
bool areRowsPalindromes(char matrix[][MAX], int n)
{
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n/2;j++)
        {
            if (matrix[i][j] != matrix[i][n - 1 - j])
            {
                return false;
            }
        }
    }
    return true;
}
bool isMagicPalindrome(char matrix[][MAX], int n)
{
    if (areRowsPalindromes(matrix, n) && areColsPalindrome(matrix, n) && isMainDiagonalPalindrome(matrix, n) && isSecondaryDiagonalPalindrome(matrix, n))
    {
        return true;
    }
    else
        return false;
}
void setMatrix(char matrix[][MAX], int n)
{
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            char x = 0;
            cin >> x;
            matrix[i][j] = x;
        }
    }
}
int main()
{
    int n = 0;
    cout << "Enter size of matrix: ";
    cin >> n;
    char matrix[MAX][MAX];
    cout << "Enter matrix" << endl;
    setMatrix(matrix, n);
    if (isMagicPalindrome(matrix, n))
        cout << "Magic palindrome";
    else
        cout << "Not magic palindrome";
}
