#include <iostream>
using namespace std;

constexpr int MAX_NAME_LENGTH = 50;
size_t strlen(const char arr[]) {
    size_t counter = 0;
    while (arr[counter++]);
    return counter - 1;
}
size_t rows(const char** arr) {
    size_t counter = 0;
    while (arr[counter++]);
    return counter - 1;
}
void del(char** arr){
    const size_t len = rows((const char**)arr);
    for (size_t i = 0; i < len; i++)
        delete[] arr[i];
    delete[] arr;
}
void strcpy(char dest[], char src[]) {
    const size_t len = strlen(src);
    for (int i = 0; i < len; i++)
        dest[i] = src[i];
    dest[len] = '\0';
}
void resize(char*** arr) {
    const size_t len = rows((const char**)*arr);
    char** newArr = new char*[len + 2];
    for (size_t i = 0; i < len; i++)
        newArr[i] = (*arr)[i];
    newArr[len] = nullptr;
    newArr[len + 1] = nullptr;
    delete[] *arr;
    *arr = newArr;
}
void resize(int*& arr, const size_t len) {
    int* newArr = new int[len + 1];
    for (size_t i = 0; i < len; i++)
        newArr[i] = arr[i];
    delete[] arr;
    arr = newArr;
}
bool equals(const char arr[], const char arr1[]) {
    const size_t len1 = strlen(arr), len2 = strlen(arr1);
    if (len1 != len2)
        return false;
    for (size_t i = 0; i < len1; i++)
        if (arr[i] != arr1[i])
            return false;
    return true;
}
bool contains(const int arr[], const size_t len, const int num) {
    for (size_t i = 0; i < len; i++)
        if (arr[i] == num)
            return true;
    return false;
}
void shiftLeft(char*** arr, const size_t index) {
    const size_t len = rows((const char**)*arr);
    char** newArr = new char*[len];
    for (size_t i = 0; i < index; i++)
        newArr[i] = (*arr)[i];
    for (size_t i = index; i < len - 1; i++)
        newArr[i] = (*arr)[i + 1];
    newArr[len - 1] = nullptr;
    delete[] (*arr)[index];
    delete[] *arr;
    *arr = newArr;
}
int indexOf(const int arr[], const int len, const int num) {
    for (int i = 0; i < len; i++)
        if (arr[i] == num)
            return i;
    return -1;
}
void shiftLeft(int*& arr, const size_t index, const size_t len) {
    int* newArr = new int[len - 1];
    for (size_t i = 0; i < index; i++)
        newArr[i] = arr[i];
    for (size_t i = index; i < len - 1; i++)
        newArr[i] = arr[i + 1];
    delete[] arr;
    arr = newArr;
}
int main() {
    char command[7];
    char** childrenNames = new char*[1];
    childrenNames[0] = nullptr;
    char** giftNames = new char*[1];
    giftNames[0] = nullptr;
    int* sackNumbers = new int[1];
    char childName[MAX_NAME_LENGTH], giftName[MAX_NAME_LENGTH];
    int sackNum;
    int pos = 0;
    while (cin >> command)
        if (equals(command, "end")) {
            del(childrenNames);
            del(giftNames);
            delete[] sackNumbers;
            break;
        }
        else if (equals(command, "add")) {
            cin >> childName >> giftName >> sackNum;
            if (contains(sackNumbers, pos, sackNum)) {
                cout << "Oops! Could not add " << giftName << " for " << childName << ", because bag " << sackNum << " is already occupied!" << endl;
                continue;
            }
            resize(&childrenNames);
            resize(&giftNames);
            resize(sackNumbers, pos);
            childrenNames[pos] = new char[strlen(childName) + 1];
            giftNames[pos] = new char[strlen(giftName) + 1];
            sackNumbers[pos] = sackNum;
            strcpy(childrenNames[pos], childName);
            strcpy(giftNames[pos], giftName);
            pos++;
            cout << "Added " << giftName << " for " << childName << " at bag " << sackNum << "!" << endl;
        }
        else if (equals(command, "remove")) {
            cin >> sackNum;
            if (!contains(sackNumbers, pos, sackNum))
                continue;
            const size_t index = indexOf(sackNumbers, pos, sackNum);
            cout << "Removed " << giftNames[index] << " for " << childrenNames[index] << " from bag " << sackNumbers[index] << "! Bag " << sackNum << " is now empty!" << endl;
            shiftLeft(&childrenNames, index);
            shiftLeft(&giftNames, index);
            shiftLeft(sackNumbers, index, pos);
            pos--;
        }
        else if (equals(command, "print")) {
            cout << "List of gifts:" << endl;
            for (int i = 0; i < pos; i++)
                cout << childrenNames[i] << " - " << giftNames[i] << " (bag " << sackNumbers[i] << ")" << endl;
        }
}