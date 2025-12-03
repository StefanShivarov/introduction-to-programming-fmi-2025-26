# Указатели. Адресна аритметика. Символни низове. Операции със символни низове

### Указатели

Указател е променлива, която съхранява адреса в паметта на друга променлива. Вместо да съдържа стойност директно, указателят посочва мястото, където се намира тази стойност.

```cpp
int a = 5;          // Обикновена променлива
int* ptr = &a;        // Указател към променливата 'a'

cout << ptr << endl; // 00000046508FFBA4 (адрес)
cout << *ptr << endl; // 5
```

- `*ptr` - **дерефериране**

- Указателите могат да имат неутрална стойност - `nullptr`
- `nullptr` сочи към адрес 0x00000000
- `nullptr` не може да се дереферира!
- Може да съдържа както адреса на някоя променлива, така и нулев адрес (`nullptr`) или някоя непозволена памет (което е източник на грешки).
- Адресът, който съдържа указателят, може да се променя.
- Може да се извършват промени по данните в съответния адрес.

```cpp
int* ptr = nullptr;
cout << ptr << endl; // 0000000000000000
int num = 7;
cout << ptr << endl;
ptr = &num;

cout << ptr << endl; // 000000733EAFF604
cout << *ptr << endl; // 7

(*ptr)++;

cout << num << endl; // 8 (променихме стойноста на променливата num, чрез указателя ptr, сочещ към адреса на num)

int anotherNumber = 24;

ptr = &anotherNumber;

cout << ptr << endl; // 000000733EAFF624
cout << *ptr << endl; // 24

(*ptr)--;

cout << num << endl; // 8
cout << anotherNumber << endl; // 23
```
### Указатели към константи/Константни указатели
Указателите към константа – НЕ може да се променя стойността на променливата, към която сочат.
- `const int*` - указател към константа
- `int const*` - указател към константа

```cpp
const int q = 5;
int const* p = &q;

*p = 7; // Compilation error

const int q2 = 7;

p = &q2; // valid	
```

Константните указатели са като референциите, но са указатели.
Може да се променя стойността на променливата, но НЕ може да се променя да сочи към друга променлива.
- `int* const` – константен указател

```cpp
int q = 5;
int *const p = &q;
*p = 7; // valid

const int q2 = 7;
p = &q2; // Compilation error
```

#### Spiral Rule
Правилото гласи, започнете от името на променливата и се придвижваме по посока на часовниковата стрелка до следващия указател или тип.

![Spiral rule](https://velog.velcdn.com/images/beechwood/post/31ad6ffd-74cd-4bd9-8205-4c3bf7bba574/image.png)


---

### Адресна аритметика

Адресната аритметика позволява манипулация на адреси в указатели.

Чрез операторите +, -, +=, -=, ++, -- можем да местим адреса към който сочи указател с даден брой позиции. Тези позиции се изчисляват спрямо големината в байтове на конкретния тип (`sizeof(int) = 4`, `sizeof(bool) = 1` и т.н.). Тоест ако имаме `int* ptr`, то при `ptr++`, той ще се премести с 4 байта напред, ако е `bool* ptr`, ще се премести с 1 байт.

```cpp
#include <iostream>
using namespace std;

int main() {

    int num = 10;
    int* ptr = &num;

    cout << ptr << endl; // 0000000F56FDFC74
    cout << ++ptr << endl; // 0000000F56FDFC78
    
    ptr += 3;

    cout << ptr << endl; // 0000000F56FDFC84

    ptr -= 4;

    cout << ptr << endl; // 0000000F56FDFC74

    bool* anotherPtr = nullptr;
    cout << anotherPtr << endl; // 0000000000000000
    cout << ++anotherPtr << endl; // 0000000000000001
    cout << ++anotherPtr << endl; // 0000000000000002
    cout << ++anotherPtr << endl; // 0000000000000003
}
```

#### Указатели и масиви

```cpp
int arr[] = {1, 2, 3};
int* ptr = arr; // ptr сочи към първия елемент на масива arr

cout << ptr[0] << endl; // 1
cout << ptr[1] << endl; // 2
```

![enter image description here](https://i.ibb.co/cDcX8st/Untitled-Diagram-drawio-3.png)

```cpp
ptr++; // изместваме адреса към който сочи ptr с 1 място (4 bytes = sizeof(int)), сега ще сочи към втория елемент

cout << ptr[0]; //2;
cout << ptr[1]; //3;
```

![enter image description here](https://i.ibb.co/xLLsVK5/Untitled-Diagram-drawio-4.png)

Тоест `ptr[i]` е еквивалентно на `*(ptr + i)`

---

### Символни низове в C++

Символните низове са поредици от символи, които се използват за работа с текст в програми. В C++ те могат да бъдат представени по два основни начина:

- `char[]`
- [`std::string`](https://cplusplus.com/reference/string/string/)

### Символни низове като масиви от символи

Символните масиви се дефинират като масиви от тип `char`, завършващи със специален символ `\0` - **терминираща нула**. Този символ бележи края на низа.

```cpp
#include <iostream>
using namespace std;

int main() {
    char name[] = "Stefan"; // Символен масив
    char name2[] = {'S', 't', 'e', 'f', 'a', 'n', '\0'}; // еквивалентно
    cout << name << endl; // Stefan

    // Достъп до символи по индекс
    int index = 0;
    while(name[index] != '\0') {
        cout << name[index] << " "; // S t e f a n
        index++;
    }
}
```

Размерът на масива трябва да е достатъчен, за да побере всички символи + `\0` !

```c++
    char word[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
    char word[6] = { 'H', 'e', 'l', 'l', 'o' }; //обикновен масив от символи
    char word[5] = { 'H', 'e', 'l', 'l', 'o' }; //обикновен масив от символи
    char word[100] = "Hello";
    char word[5] = "Hello"; // невалидно, понеже "" включват в себе си '\0‘
    char word[6] = "Hello";
```
---
### Tерминираща нула - `\0`

Първият символ в ASCII таблицата, с код 0 – т.е **char(0)**.
Брои се като елемент и **влияе** на размера на масив.
Използва се като **прекъсвач (терминатор)** от много функции за символни низове, за да се определя края на низа.

```c++
    //Може да се сложи в средата на масив от символи
    char a []= {'H', 'e', 'l', 'l','\0', 'o'}; //символният низ е “Hell”
```

## Как изглежда в паметта

```c++
    char str[] = {'t', 'e', 's', 't', '\0'};
    char str2[] = "test"; //equivalent to str
    char str3[7] = "test";
```

![enter image description here](https://i.ibb.co/ZmRwt6R/Untitled-Diagram-drawio-5.png)

---
### Четене на символни низове от конзолата

1. **Използване на `cin`**:
Операторът `>>` чете символен низ до първия срещнат празен символ (разстояние, табулация, нов ред).

    ```cpp
    #include <iostream>
    using namespace std;

    int main() {
        char name[50];
        cin >> name; // Чете до първия интервал
        cout << name << endl;

        return 0;
    }
    ```
    Ако въведете текст с интервали, ще се прочете само първата дума.

2. **Използване на `cin.getline`**
Функцията `cin.getline` позволява четене на цели редове, включително интервали, докато не се срещне символ за нов ред (`\n`) или определен максимален брой символи.

    ```cpp
    #include <iostream>
    using namespace std;

    int main() {
        char fullName[100];
        cin.getline(fullName, 100); // Чете до 99 символа или нов ред
        cout << fullName << endl;

        return 0;
    }
    ```

**Смесване на `cin` и `cin.getline`**

Когато използвате cin за четене преди `cin.getline`, може да възникне проблем: cin оставя символа за нов ред (`\n`) в буфера. Това води до незабавно прекратяване на следващото извикване на `cin.getline`.

*Решение*: **Използване на `cin.ignore`**
Функцията `cin.ignore` премахва нежелания символ от входния буфер.

```cpp
#include <iostream>
using namespace std;

int main() {
    char firstName[50], fullName[100];

    cout << "Enter first name:" << endl;
    cin >> firstName;

    // Изчистване на буфера
    cin.ignore();

    cout << "Enter full name:" << endl;
    cin.getline(fullName, 100);

    cout << "First name: " << firstName << endl;
    cout << "Full name: " << fullName << endl;

    return 0;
}
```

---

### Често използвани функции от `<cstring>`:

`strlen` – намира дължината на низа (без терминиращата нула \0).

`strcpy` – копира един символен низ в друг.

`strcmp` – сравнява два символни низа.

`strcat` – добавя един символен низ към друг.
```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str1[50] = "Hello";
    char str2[50] = "World";

    // Дължина на низ
    cout << strlen(str1) << endl; // 5

    // Конкатенация
    strcat(str1, " "); // "Hello "
    strcat(str1, str2); // "Hello World"
    cout << str1 << endl; 

    // Сравнение
    if (strcmp(str1, str2) == 0)
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;

    char str3[50];

    strcpy(str2, str3);
    cout << str3 << endl; // World

    return 0;
}
```

**Често срещани грешки:**

- Липса на терминираща нула `\0`: Ако терминиращата нула липсва, операциите със символния низ може да доведат до неочаквани резултати.
- Препълване на буфера: Уверете се, че размерът на масива е достатъчен за всички символи + терминиращата нула.
- Прескачане на `getline` след `cin`
- Използване на неинициализирани символни масиви