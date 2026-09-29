#include <iostream>
#include <string>
using namespace std;

bool isTriangle(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0) return false;
    return (a + b > c) && (a + c > b) && (b + c > a);
}
void PrintValid(int n)
{
    string result = "";
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (isTriangle(a, b, c)) {
            result += to_string(a) + " " + to_string(b) + " " + to_string(c) + "\n";
        }
    }
    cout << result;
}
int main() 
{
    int n;
    cin >> n; 
    PrintValid(n);
    return 0;
}