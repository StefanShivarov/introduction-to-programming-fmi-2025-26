#include <iostream>
using namespace std;

int absoluteValue(int number){
    if (number > 0) { return number; }
    else { return -number; }
}
int main() {
    int a;
    cin >> a;
    cout << absoluteValue(a);   
}
