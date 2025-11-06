**1.** Опишете последователно точно какво ще изведе на екрана следният програмен фрагмент. Обосновете писмено подробно отговора си.

```cpp
for (int i = 7; i<=24; cout << i << endl) i++;
```

**2.** Ще се компилира ли следният програмен фрагмент:
```cpp
int num1 = 6;
int num2 = 12;
num2++ = ++num1 + 33;
```

**3.** 
Даден е работещ С++ код, който по въведено цяло положително число намира колко пъти се среща цифрата 3, колко пъти се среща цифрата 7, както и броя на четните и нечетните цифри. Кодът е умишлено написан с много повторения и неефективна структура. Задачата е да го преработите, като използвате функции за повтарящата се логика, намалите повторението на код, подобрите четимостта и ефективността, без да променяте функционалността и входа/изхода на програмата.

```cpp
#include <iostream>
using namespace std;

int main() {
    unsigned number;
    cin >> number;

    unsigned originalNumber = number;

    unsigned count3 = 0;
    while (number > 0) {
        unsigned d = number % 10;
        if (d == 3) {
            count3++;
        }
        number /= 10;
    }

    number = originalNumber;

    unsigned count7 = 0;
    while (number > 0) {
        unsigned d = number % 10;
        if (d == 7) {
            count7++;
        }
        number /= 10;
    }

    number = originalNumber;

    unsigned even = 0;
    while (number > 0) {
        unsigned d = number % 10;
        if (d == 0 || d == 2 || d == 4 || d == 6 || d == 8) {
            even++;
        }
        number /= 10;
    }

    number = originalNumber;

    unsigned odd = 0;
    while (number > 0) {
        unsigned d = number % 10;
        if (d == 1 || d == 3 || d == 5 || d == 7 || d == 9) {
            odd++;
        }
        number /= 10;
    }

    cout << "Count of 3: " << count3 << endl;
    cout << "Count of 7: " << count7 << endl;
    cout << "Even digits: " << even << endl;
    cout << "Odd digits: " << odd << endl;

    return 0;
}
```
