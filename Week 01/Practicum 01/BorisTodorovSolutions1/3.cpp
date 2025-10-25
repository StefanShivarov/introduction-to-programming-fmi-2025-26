#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	int seconds;
	int minutes;
	int hours;
	int days;
	cin >> seconds;
	minutes = seconds / 60;
	seconds = seconds % 60;
	hours = minutes / 60;
	minutes = minutes % 60;
	days = hours / 24;
	hours = hours % 24;
	cout << "days-";cout << days;cout << " hours-";cout << hours;cout << " minutes-";cout << minutes;cout << " seconds-";cout << seconds;
}
