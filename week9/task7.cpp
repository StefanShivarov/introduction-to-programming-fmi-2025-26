#include <iostream>
using namespace std;

constexpr int MAX = 50;
void fromDecimalToBinary(char num[MAX], unsigned number, int& counter) {
    while (number) {
        num[counter++] = number % 2 + '0';
        number /= 2;
    }
}
int main() {
    char num[MAX];
    int counter = 0;
    int number, position;
    cout << "Number: ";
    cin >> number;
    cout << "Position: ";
    cin >> position;
    fromDecimalToBinary(num, number, counter);
    for (int i = 0; i < counter; i++)
        if (counter - i - 1 == position)
            cout << num[i] << endl;//от дясно наляво
    for (int i = 0; i < counter; i++)
        if (i == position)
            {cout << num[i];}//от ляво надясно
}