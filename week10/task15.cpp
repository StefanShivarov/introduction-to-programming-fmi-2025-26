#include <iostream>
using namespace std;

constexpr int MAX = 100;
size_t strlen(const char str[]) {
    int length = 0;
    while (str[length++] != '\0');
    return length - 1;
}
int word_count(const char str[]) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == ' ')
            count++;
    return count + 1;
}
void print_word_at_index(const char str[], const int index) {
    int counter = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (index == 0 || counter == index) {
            if (str[i] == ' ')
                break;
            cout << str[i];
        }
        else if (index == word_count(str) - 1) {
            if (counter == index)
                cout << str[i];
        }
        if (str[i] == ' ')
            counter++;
    }
}
void order(int word_pos[MAX], const char str[]) {
    int beg = 0, end = word_count(str) - 1, counter = 0;
    while (counter < word_count(str))
        if (counter % 2)
            word_pos[end--] = counter++;
        else
            word_pos[beg++] = counter++;
}
void printUsingArrayValue(int word_pos[], char str[]) {
    for (int i = 0; i < word_count(str); i++) {
        print_word_at_index(str, word_pos[i]);
        if (i == word_count(str) - 1)
            cout << ".";
        else
            cout << " ";
    }
}
int main() {
    char str[MAX];
    cin.getline(str, MAX);
    int word_pos[MAX];
    order(word_pos, str);
    printUsingArrayValue(word_pos, str);
}