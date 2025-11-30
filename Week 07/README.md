# Седмица 07 - Многомерни масиви. Матрици. Обхождане на матрица

**Многомерните масиви** са масиви, които съдържат други масиви като елементи. Най-често използваният многомерен масив е двумерният, който можем да си представим като матрица с редове и колони.

Двумерен масив се декларира, като се посочи типът на данните, последван от два размера – един за редовете и един за колоните.

```cpp
int matrix[3][4]; // Декларира матрица от 3 реда и 4 колони
```

Двумерен масив може да бъде инициализиран директно при декларацията му:

```cpp
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

**Обхождане на двумерен масив:**

```cpp
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};

for (int i = 0; i < 2; i++) {           // Обхожда редовете
    for (int j = 0; j < 3; j++) {       // Обхожда колоните
        cout << matrix[i][j] << " ";    // Извежда текущия елемент
    }
    cout << endl; // Принтираме нов ред след всеки ред от матрицата
}
// Изход:
// 1 2 3
// 4 5 6
```

---

**Важно:** При подаване на многомерен масив, освен първото измерение, останалите трябва да са известни, за да може компилаторът да изчисли правилно адресите на елементите.

_Можем и да не подаваме размерите на измеренията на многомерни масиви, но само ако те са динамично заделени (за това по-нататък в курса)_


```cpp
void printMatrix(int matrix[][3], int rows) { // Трябва да уточним броя на колоните (3 в този случай)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printMatrix(matrix, 2); // Извикваме функцията и подаваме двумерен масив
    return 0;
}
// Изход:
// 1 2 3
// 4 5 6

```

```cpp
#include <iostream>
using namespace std;

void modifyMatrix(int matrix[][3], int rows) { // Указател към масив с 3 колони
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] += 10; // Добавяме 10 към всеки елемент
        }
    }
}

int main() {
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    modifyMatrix(matrix, 2); // Подаваме двумерен масив чрез указател

    // Извеждаме променената матрица
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
// Изход:
// 11 12 13
// 14 15 16

```

---

### Диагонали на матрица

![](https://www.opentechguides.com/images/howto/howto_24301.webp)

#### Главен диагонал

Главният диагонал на квадратна матрица се състои от елементите, при които индексите на реда и колоната са равни: А[i][j], i = j.

#### Второстепенен диагонал

Второстепенният диагонал съдържа елементите, при които индексите на реда и колоната са взаимно допълващи до размера на матрицата n: А[i][j], j = n - 1 - i.

**Примерен код за намиране на сумите на двете диагонали**:

```cpp
const int SIZE = 3;

int main() {
    int mainDiagonalSum = 0;
    int secondaryDiagonalSum = 0;
    int matrix[SIZE][SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for (int i = 0; i < SIZE; i++) {
        mainDiagonalSum += matrix[i][i];
        secondaryDiagonalSum += matrix[i][SIZE - 1 - i];
    }

    std::cout << "Main diagonal sum: " << mainDiagonalSum << std::endl;
    std::cout << "Secondary diagonal sum: " << secondaryDiagonalSum << std::endl;
}
```

---

### Друго по-интересно диагонално обхождане на матрица:

![](https://media.geeksforgeeks.org/wp-content/uploads/zigzag-1.png)

```cpp
#include <iostream>
using namespace std;

const int ROWS = 5;
const int COLS = 4;

void printMatrixDiagonals(const int matrix[ROWS][COLS]) {
    // Обхождаме диагоналите, които започват от първата колона
    for (int startRow = 0; startRow < ROWS; ++startRow) {
        int row = startRow;
        int col = 0;
        // Преминаваме диагонално нагоре вдясно
        while (row >= 0 && col < COLS) {
            cout << matrix[row][col] << " ";
            row--;
            col++;
        }
        cout << endl;
    }

    // Обхождаме диагоналите, които започват от последния ред (без първата клетка)
    for (int startCol = 1; startCol < COLS; ++startCol) {
        int row = ROWS - 1;
        int col = startCol;
        // Преминаваме диагонално нагоре вдясно
        while (row >= 0 && col < COLS) {
            cout << matrix[row][col] << " ";
            row--;
            col++;
        }
        cout << endl;
    }
}


int main() {
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20}
    };

    printMatrixDiagonals(matrix);

    /*
    1
    5 2
    9 6 3
    13 10 7 4
    17 14 11 8
    18 15 12
    19 16
    20
    */
}

```

---

### Спирално обхождане на матрица

![](https://files.prepinsta.com/2022/05/Spiral-Traversal-of-a-Matrix-in-Python-768x421.webp)

```cpp
#include <iostream>
using namespace std;

const int ROWS = 4;
const int COLS = 4;
const int MAX_SIZE = 50;

void spiralTraversal(const int matrix[ROWS][COLS]) {
    int i, left = 0, right = COLS - 1, top = 0, bottom = ROWS - 1;

    while (left <= right && top <= bottom) {

        /* Print the first row
        from the remaining rows */
        for (i = left; i <= right; ++i) {
            cout << matrix[top][i] << " ";
        }
        top++;

        /* Print the last column
        from the remaining columns */
        for (i = top; i <= bottom; ++i) {
            cout << matrix[i][right] << " ";
        }
        right--;

        /* Print the last row from
        the remaining rows */
        if (top <= bottom) {
            for (i = right; i >= left; --i) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }

        /* Print the first column from
        the remaining columns */
        if (left <= right) {
            for (i = bottom; i >= top; --i) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
}

int main()
{
    int matrix[ROWS][COLS] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };

    spiralTraversal(matrix); // 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
}
```
