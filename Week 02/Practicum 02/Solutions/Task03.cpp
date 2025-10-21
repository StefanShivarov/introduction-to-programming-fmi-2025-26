#include <iostream>

using namespace std;

int main() {
	int prompt_number = 0;
	int factorial = 1;

	cout << "Please enter the number to count a factorial: ";
	cin >> prompt_number;
	for (int i = 1; i <= prompt_number; i++) {
		factorial *= i;
	}

	cout << "Out: " << factorial;

	return 0;
}