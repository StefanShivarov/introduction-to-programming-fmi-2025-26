#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50}; 
    int key;
    bool found = false;

    cout << "Enter the number to search: ";
    cin >> key;

    for (int i = 0; i < 5; i++) {
        if (arr[i] == key) {
            cout << "Element found at index " << i << endl;
            found = 1;
            break;
        }
    }

    if (!found)
        cout << "Element not found in the array." << endl;

    return 0;
}
