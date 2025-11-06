#include <iostream>
using namespace std;

int main() {
    int arr[6] = {5, 10, 15, 20, 25, 30};  // Array must be sorted
    int key;
    int low = 0, high = 5, mid;
    bool found = false;

    cout << "Enter the number to search: ";
    cin >> key;

    while (low <= high) {
        // Find the middle index safely (avoids overflow)
        mid = low + (high - low) / 2 ;
        
        //mid = (low + high) / 2;

        if (arr[mid] == key) {
            cout << "Element found at index " << mid << endl;
            found = true;
            break;
        } 
        else if (arr[mid] < key) {
            low = mid + 1;  // Search right half
        } 
        else {
            high = mid - 1; // Search left half
        }
    }

    if (!found)
        cout << "Element not found in the array." << endl;

    return 0;
}
