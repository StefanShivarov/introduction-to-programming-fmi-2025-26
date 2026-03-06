#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;
    int copyOfNum = num;
    int counter = 0;
    while (num)
        counter++, num /= 10;
    int arr[counter];
    for (int i = 0; i < counter; i++)
        arr[i] = copyOfNum % 10, copyOfNum /= 10;
    bool b = true;
    for (int i = 0, j = counter - 1; i < counter; i++, j--)
        if (arr[i] != arr[j])
            b = false;
    if (b)
        cout << "Yes";
    else
        cout << "No";
}