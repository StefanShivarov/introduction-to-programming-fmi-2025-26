#include <iostream>
using namespace std;

const int MAX = 10;
void swap(int &a, int &b) {
    a += b;
    b = a - b;
    a -= b;
}
void printMatrix(const int matrix[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
int sumAll(const int matrix[][MAX], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sum += matrix[i][j];
    return sum;
}
double avg(const int matrix[][MAX], int n) {
    return (double) sumAll(matrix, n) / (n * n);
}
void printRowSums(const int matrix[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++)
            sum += matrix[i][j];
        cout << "Sum of row " << i << ": " << sum << endl;
    }
}
void printColSums(const int matrix[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++)
            sum += matrix[j][i];
        cout << "Sum of column " << i << ": " << sum << endl;
    }
}
int getMin(const int matrix[][MAX], int n) {
    int min = matrix[0][0];
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] < min)
                min = matrix[i][j];
    return min;
}
int getMax(const int matrix[][MAX], int n) {
    int max = matrix[0][0];
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] > max)
                max = matrix[i][j];
    return max;
}
int mainDiagonalSum(const int matrix[][MAX], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += matrix[i][i];
    return sum;
}
int secondaryDiagonalSum(const int matrix[][MAX], int n) {
    int sum = 0;
    for (int i = n - 1, j = 0; i >= 0; i--, j++)
        sum += matrix[i][j];
    return sum;
}
void transpose(int matrix[][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            if (i != j)
                swap(matrix[i][j], matrix[j][i]);
}
void rotateMatrix(int matrix[][MAX], int n) {
    int rotatedMatrix[MAX][MAX];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            rotatedMatrix[j][n - i - 1] = matrix[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = rotatedMatrix[i][j];
}
int sumEven(int matrix[][MAX], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] % 2 == 0)
                sum += matrix[i][j];
    return sum;
}
int sumOdd(int matrix[][MAX], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] % 2 == 1)
                sum += matrix[i][j];
    return sum;
}
void replaceNegativeWithZero(int matrix[][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] < 0)
                matrix[i][j] = 0;
}
bool isSymmetric(int matrix[][MAX], int n) {
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (matrix[i][j] != matrix[j][i])
                return false;
    return true;
}
int main() {
    int n;
    cout << "Enter n: ";
    while (cin >> n) {
        if (n <= MAX)
            break;
        cout << "Invalid input, try again, n must be less than 11!" << endl;
        cout << "Enter n: ";
    }
    int matrix[MAX][MAX];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cout << "Enter matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    printMatrix(matrix, n);
    int temp = -1;
    cout << "Choose operation: " << endl;
    cout << "1. Sum and Average" << endl;
    cout << "2. Row and Column Operations" << endl;
    cout << "3. Minimum and Maximum" << endl;
    cout << "4. Diagonal Operations" << endl;
    cout << "5. Transpose of the Matrix" << endl;
    cout << "6. Rotate the Matrix" << endl;
    cout << "7. Sum of even and odd numbers" << endl;
    cout << "8. Replace all negative numbers with zero" << endl;
    cout << "9. Check for symmetry" << endl;
    cout << "0. Exit" << endl;
    while (temp) {
        cin >> temp;
        if (temp == 1) {
            cout << "Sum of matrix: " << sumAll(matrix, n) << endl;
            cout << "Average of matrix: " << avg(matrix, n) << endl;
        }
        else if (temp == 2) {
            printRowSums(matrix, n);
            printColSums(matrix, n);
        }
        else if (temp == 3) {
            cout << "Smallest element: " << getMin(matrix, n) << endl;
            cout << "Largest element: " << getMax(matrix, n) << endl;
        }
        else if (temp == 4) {
            cout << "Sum of main diagonal: " << mainDiagonalSum(matrix, n) << endl;
            cout << "Sum of secondary diagonal: " << secondaryDiagonalSum(matrix, n) << endl;
            cout << "Difference of diagonal sums: " << (mainDiagonalSum(matrix, n) - secondaryDiagonalSum(matrix, n) > 0 ? mainDiagonalSum(matrix, n) - secondaryDiagonalSum(matrix, n) : secondaryDiagonalSum(matrix, n) - mainDiagonalSum(matrix, n)) << endl;
        }
        else if (temp == 5) {
            cout << "Matrix before transposing: " << endl;
            printMatrix(matrix, n);
            transpose(matrix, n);
            cout << "Matrix after transposing: " << endl;
            printMatrix(matrix, n);
        }
        else if (temp == 6) {
            cout << "Matrix before rotating: " << endl;
            printMatrix(matrix, n);
            rotateMatrix(matrix, n);
            cout << "Matrix after rotating: " << endl;
            printMatrix(matrix, n);
        }
        else if (temp == 7) {
            cout << "Sum of even: " << sumEven(matrix, n) << endl;
            cout << "Sum of odd: " << sumOdd(matrix, n) << endl;
        }
        else if (temp == 8) {
            cout << "Matrix before replacing negatives with zeros: " << endl;
            printMatrix(matrix, n);
            replaceNegativeWithZero(matrix, n);
            cout << "Matrix after replacing negatives with zeros: " << endl;
            printMatrix(matrix, n);
        }
        else if (temp == 9) {
            cout << "Symmetry: ";
            if (isSymmetric(matrix, n))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}