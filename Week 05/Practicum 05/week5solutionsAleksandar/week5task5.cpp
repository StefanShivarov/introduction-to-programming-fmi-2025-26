#include <iostream>
#include <cmath>
using namespace std;

int log(int x, int y){
    int result = x, i=0;
    while (result <= y)
    {
        result *= x; i++;
    }
    return i;
}
int main() {
    int x, y;
    cin >> x >> y;
    cout << log(x, y);
}
