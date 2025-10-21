#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    int n;
    cin >> n;

    int totalRows = 2 * n - 1; // определяме броя на редовете (височина)

    for (int i = 0; i < totalRows; i++) {
        // Определяме maxNumInRow (броя числа в лявата и дясната част)
        // или по друг начин казано: най - голямото число на всеки ред
        int maxNumInRow = (i < n) ? i + 1 : 2 * n - i - 1;

        // Лява част на панделката за конкретния ред i
        for (int j = 1; j <= maxNumInRow; j++) {
            cout << j << " ";
        }

        // Междинни интервали или тирета на средния ред
        if (i == n - 1) {
            // когато сме на средния ред, принтираме тирета
            for (int j = 0; j < n; j++) {
                cout << "-";
            }
        } else {
            // в противен случай принтираме интервали

            /*
             * Панделката е с широчина 5*n.
             * От цялата широчина вадим броя цифри на реда и броя интервали
             * (по 1 след всяка цифра ако са от лявата част, по 1 преди всяка ако са от дясната част),
             * което е 5*n - 4*maxNumInRow
            */
            int spacesCount = 5 * n - 4 * maxNumInRow;
            for (int j = 0; j < spacesCount; j++) {
                cout << " ";
            }
        }

        // Дясна част на панделката за конкретния ред i
        for (int j = maxNumInRow; j >= 1; j--) {
            cout << " " << j;
        }

        cout << endl;
    }
}
