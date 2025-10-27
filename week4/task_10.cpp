#include <iostream>
using namespace std;

int sortDigits(int n)
{
    if (n < 0)
    {
        n = -n;
    }

    int result = 0;

    while (n > 0) {
        int temp = n; 
        int minDigit = 9; //segashna nai-malka cifra
        int minPos = 1; //kude e nai-malkata cifra(edinici, stotici...)
        int posNow = 1; //kude e razglejdanata na momenta cifra(edinici, desetici...)
        while (temp > 0) {
            int digit = temp % 10;
            if (digit <= minDigit) {
                minDigit = digit;
                minPos = posNow;
            }
            temp /= 10;
            posNow *= 10;
        }
        result = result * 10 + minDigit;
        n = (n / (minPos * 10)) * minPos + (n % minPos);
    }

    return result;
}
int main()
{
    int n;
    cin >> n;
    cout << sortDigits(n);
}

//zadacha 11 daje ne razbrah uslovieto
