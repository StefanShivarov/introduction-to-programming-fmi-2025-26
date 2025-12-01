#include <iostream>

constexpr unsigned MIN_DAY = 1;
constexpr unsigned MAX_DAY = 31;
constexpr int NO_EXAM_DAY = -1;
constexpr int COMMAND_BUFFER_SIZE = 100;

constexpr char UPPER_A = 'A';
constexpr char UPPER_Z = 'Z';
constexpr int CASE_DIFF = 'a' - 'A';

bool isValidDay(unsigned day) {
	return day >= MIN_DAY && day <= MAX_DAY;
}

void addExam(unsigned day, unsigned& month) {
	if (!isValidDay(day)) {
		return;
	}

	unsigned mask = 1;
	mask <<= (day - 1);
	month |= mask;
}

void removeExam(unsigned day, unsigned& month) {
	if (!isValidDay(day)) {
		return;
	}

	unsigned mask = 1;
	mask <<= (day - 1);
	month &= ~mask;
}

bool isExamDay(unsigned day, unsigned month) {
	if (!isValidDay(day)) {
		return false;
	}

	unsigned mask = 1;
	mask <<= (day - 1);
	return month & mask;
}

int getExamDaysCount(unsigned month) {
	int count = 0;

	for (int i = 0; i < MAX_DAY; i++) {
		unsigned mask = 1;
		mask <<= i;

		if (month & mask) {
			count++;
		}
	}
	return count;
}

int getEarliestExamDay(unsigned month) {
	for (int i = 0; i < MAX_DAY; i++) {
		unsigned mask = 1;
		mask <<= i;

		if (month & mask) {
			return i + 1;
		}
	}
	return NO_EXAM_DAY;
}

void getAllExamDays(unsigned month) {
	for (int i = 0; i < MAX_DAY; i++) {
		unsigned mask = 1;
		mask <<= i;

		if (month & mask) {
			std::cout << (i + 1) << " ";
		}
	}
}

unsigned getUnion(unsigned first, unsigned second) {
	return first | second;
}

unsigned getIntersection(unsigned first, unsigned second) {
	return first & second;
}

bool equalsIgnoreCase(const char* a, const char* b) {
	while (*a && *b) {
		char ca = *a;
		char cb = *b;

		if (ca >= UPPER_A && ca <= UPPER_Z) {
			ca += CASE_DIFF;
		}
		if (cb >= UPPER_A && cb <= UPPER_Z) {
			cb += CASE_DIFF;
		}

		if (ca != cb) {
			return false;
		}

		++a;
		++b;
	}
	return *a == *b;  // both must end
}

void processCommand(const char* command, unsigned& month) {
	if (equalsIgnoreCase(command, "ADD")) {
		unsigned day;
		std::cin >> day;
		addExam(day, month);
		std::cout << "Added exam on day " << day << "." << std::endl;
	}
	else if (equalsIgnoreCase(command, "REMOVE")) {
		unsigned day;
		std::cin >> day;
		removeExam(day, month);
		std::cout << "Removed exam from day " << day << "." << std::endl;
	}
	else if (equalsIgnoreCase(command, "CHECK")) {
		unsigned day;
		std::cin >> day;
		if (isExamDay(day, month)) {
			std::cout << "Yes, there is an exam on day " << day << "." << std::endl;
		}
		else {
			std::cout << "No, there is no exam on day " << day << "." << std::endl;
		}
	}
	else if (equalsIgnoreCase(command, "COUNT")) {
		int count = getExamDaysCount(month);
		std::cout << "Exam days count: " << count << std::endl;
	}
	else if (equalsIgnoreCase(command, "FIRST")) {
		int day = getEarliestExamDay(month);
		if (day == NO_EXAM_DAY) {
			std::cout << "No exams scheduled." << std::endl;
		}
		else {
			std::cout << "First exam day: " << day << std::endl;
		}
	}
	else if (equalsIgnoreCase(command, "LIST")) {
		if (getExamDaysCount(month) == 0) {
			std::cout << "No exams scheduled." << std::endl;
		}
		else {
			std::cout << "Exam days: ";
			getAllExamDays(month);
			std::cout << std::endl;
		}
	}
}

int main() {
	unsigned month = 0;
	char command[COMMAND_BUFFER_SIZE];

	while (std::cin >> command) {
		if (equalsIgnoreCase(command, "END")) {
			break;
		}
		processCommand(command, month);
	}

/*
* Demo for the union and intersection functions
	unsigned monthA = 0;
	unsigned monthB = 0;

	addExam(5, monthA);
	addExam(10, monthA);

	addExam(10, monthB);
	addExam(20, monthB);

	unsigned uni = getUnion(monthA, monthB);
	unsigned inter = getIntersection(monthA, monthB);

	getAllExamDays(monthA);
	std::cout << std::endl;
	getAllExamDays(monthB);
	std::cout << std::endl;
	getAllExamDays(uni);
	std::cout << std::endl;
	getAllExamDays(inter);
	*/

	return 0;
}
