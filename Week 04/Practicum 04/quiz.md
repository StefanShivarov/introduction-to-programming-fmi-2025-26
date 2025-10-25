# Snippets quiz 🤔 - променливи, if-else/switch, цикли

```c++
#include <iostream>
int main()
{
    int a = 2;
    int b = 4;
    int c = a * b;
    std::cout << (++a) * c + (b--) / 3 + c;
}
```
<br>

```c++
#include<iostream>

int main() {
    int a = 0;

    if (a = 5) {
        std::cout << "true";
    }
    else {
        std::cout << "false";
    }
}
```
<br>

```c++
#include<iostream>

int main() {
    int a = 1;

    if (a == 0); {
        std::cout << "true";
    }
}
```
<br>

```c++
#include <iostream>
int main()
{
    int a = 2;
    int b = 4;
    if(a, b - 2* a)
        std::cout << a;
    else
        std::cout << 100;
}
```
<br>

```c++
#include<iostream>

int main() {
    switch (x) {
    default:
        std::cout << "no match\n";
        break;
    case 1:
        std::cout << "one\n";
        break;
    case 2:
        std::cout << "two\n";
        break;
    }
}
```
<br>

```c++
#include<iostream>

int main() {
    int x=3;
    switch (x) {
    default:
        std::cout << "no match -> ";
    case 1:
        std::cout << "one-or-after-default\n";
        break;
    case 2:
        std::cout << "two\n";
        break;
    }
}
```
<br>

```c++
#include <iostream>

int main() {
    int x = 1;
    switch (x) {
        case 1:
            std::cout << "A";
        case 2:
            std::cout << "B";
        default:
            std::cout << "C";
    }
}
```
<br>

```c++
#include <iostream>

int main() {
    for (int i = 0, j = 10; i < j; i++, j--)
        std::cout << i << " " << j << "\n";
}
 
```
<br>

```c++
#include <iostream>
int main()
{
    int a = 10;
    while (a)
    {
        a++;
        std::cout << a--<<std::endl;
        a--;
    }
}
```

<br>

```c++
#include <iostream>

int main() {
    for (int i = (std::cout << "Uvajaema gospojo\n", 0);i <= 100;(std::cout << "Nqma da narushavam disciplinata v chas\n", ++i)) {}
}

```
<br>   


```c++
#include <iostream>
int main()
{
    int a = 0;
    do
    {
        std::cout << "a";
    } while(a);
}
```
<br>