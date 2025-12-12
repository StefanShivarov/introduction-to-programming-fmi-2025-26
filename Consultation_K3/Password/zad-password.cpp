#include <iostream>

const size_t MAX_SIZE = 1024;

const size_t MAX_PASS_LEN = 255;
const size_t MIN_PASS_LEN = 8;

const char CENSOR_SYMB = 'X';

size_t myStrlen(const char* str)
{
	if (!str)
	{
		return 0;
	}

	size_t count = 0;
	while (*str)
	{
		count++;
		str++;
	}

	return count;
}

bool isLowercase(char symb)
{
	return symb >= 'a' && symb <= 'z';
}

bool isUppercase(char symb)
{
	return symb >= 'A' && symb <= 'Z';
}

bool isLetter(char symb)
{
	return isLowercase(symb) || isUppercase(symb);
}

bool isDigit(char symb)
{
	return symb >= '0' && symb <= '9';
}

bool contains(char symb, const char* str)
{
	if (!str)
	{
		return false;
	}

	while (*str)
	{
		if (*str == symb)
		{
			return true;
		}
		str++;
	}

	return false;
}

bool areValidSpecials(const char* specials)
{
	if (!specials)
	{
		return false;
	}

	while (*specials)
	{
		if (isLetter(*specials) || isDigit(*specials))
		{
			return false;
		}

		specials++;
	}

	return true;
}

bool isValidPassLen(const char* pass)
{
	size_t len = myStrlen(pass);
	return pass && len >= MIN_PASS_LEN && len <= MAX_PASS_LEN;
}

bool hasUppercaseAndLowercase(const char* pass)
{
	if (!pass)
	{
		return false;
	}

	bool hasUpper = false;
	bool hasLower = false;

	while (*pass && (!hasUpper || !hasLower))
	{
		if (isUppercase(*pass))
		{
			hasUpper = true;
		}

		if (isLowercase(*pass))
		{
			hasLower = true;
		}

		pass++;
	}

	return hasUpper && hasLower;
}

bool hasAtLeastOneSpecial(const char* pass, const char* specials)
{
	if (!pass || !specials)
	{
		return false;
	}

	while (*pass)
	{
		if (contains(*pass, specials))
		{
			return true;
		}

		pass++;
	}

	return false;
}

bool isValidPassword(const char* pass, const char* specials)
{
	if (!pass || !specials)
	{
		return false;
	}

	return isValidPassLen(pass)
		&& hasUppercaseAndLowercase(pass)
		&& hasAtLeastOneSpecial(pass, specials);
}

void replaceAllWithSymb(char* pass, char symb)
{
	if (!pass)
	{
		return;
	}

	while (*pass)
	{
		*pass = symb;
		pass++;
	}
}

void swap(char& a, char& b)
{
	a ^= b;
	b ^= a;
	a ^= b;
}

void reverse(char* str)
{
	char* start = str;
	char* end = str + myStrlen(str) - 1;

	while (start < end)
	{
		swap(*start, *end);
		start++;
		end--;
	}
}

void myConcat(const char* source, char* dest)
{
	if (!source || !dest)
	{
		return;
	}

	dest += myStrlen(dest);

	while (*source)
	{
		*dest = *source;
		source++;
		dest++;
	}

	*dest = '\0';
}

void concatAllSpecialsReversedAtEnd(char* pass, const char* specials)
{
	if (!pass || !specials)
	{
		return;
	}

	char buffer[MAX_SIZE] = {};
	size_t bufferIndx = 0;

	while (*pass)
	{
		if (contains(*pass, specials))
		{
			buffer[bufferIndx++] = *pass;
		}
		pass++;
	}

	reverse(buffer);
	myConcat(buffer, pass);
}

void processString(char* pass, const char* specials)
{
	if (!pass || !specials)
	{
		return;
	}

	if (!areValidSpecials(specials))
	{
		return;
	}

	if (!isValidPassword(pass, specials))
	{
		replaceAllWithSymb(pass, CENSOR_SYMB);
	}
	else
	{
		concatAllSpecialsReversedAtEnd(pass, specials);
	}
}

int main()
{
	char str[MAX_SIZE] = "My@Password1!--Up-SI##";
	char specials[MAX_SIZE] = "!@-#";

	processString(str, specials);

	std::cout << str;
}
