# **Matrix Explorer** 

## **Overview**

In this project, you will build a program that works with a square matrix of integers. The goal is to practice using arrays, pointers, references, and functions. You will read a matrix from the user, display it, perform various operations on it, and finally transform it. Each subtask builds on the previous one, helping you strengthen your understanding step by step.

---

## **Subtasks**

### **a. Input and Output**

* Define a constant `MAX = 10`.
* Ask the user to enter the size of the matrix `n` (where `n ≤ MAX`).
* Input `n × n` integers into a 2D array named `matrix`.
* Write a function that prints the matrix in a clean, readable format:

  ```cpp
  void printMatrix(const int matrix[][MAX], int n);
  ```
* Call this function from `main()` to verify that the input and output work correctly.

---

### **b. Sum and Average**

* Write a function that calculates and returns the sum of all elements in the matrix:

  ```cpp
  int sumAll(const int matrix[][MAX], int n);
  ```
* Write another function that calculates the average of all matrix elements and returns it as a `double`.
* Print both the total sum and the average.

---

### **c. Row and Column Operations**

* Write a function that prints the sum of each row in the matrix:

  ```cpp
  void printRowSums(const int matrix[][MAX], int n);
  ```
* Write another function that prints the sum of each column:

  ```cpp
  void printColSums(const int matrix[][MAX], int n);
  ```
* Test both functions to ensure that they work correctly.

---

### **d. Minimum and Maximum**

* Write two functions to find the smallest and largest elements in the matrix:

  ```cpp
  int getMin(const int matrix[][MAX], int n);
  int getMax(const int matrix[][MAX], int n);
  ```
* Call them in `main()` and display the results.

---

### **f. Diagonal Operations**

* Write two functions to calculate the sum of the diagonals:

  ```cpp
  int mainDiagonalSum(const int matrix[][MAX], int n);
  int secondaryDiagonalSum(const int matrix[][MAX], int n);
  ```
* Print both diagonal sums and their difference.

---

### **g. Transpose of the Matrix**

* Write a function that transposes the matrix (swaps rows and columns):

  ```cpp
  void transpose(int matrix[][MAX], int n);
  ```
* Use a temporary variable to swap `matrix[i][j]` and `matrix[j][i]` for all `i < j`.
* Print the matrix before and after transposing it.

---

### **h. Rotate the Matrix**

* Write a function that rotates the matrix 90° clockwise:

  ```cpp
  void rotateMatrix(int matrix[][MAX], int n);
  ```
* Use nested loops and a temporary variable to perform the rotation.
* Display the matrix before and after the rotation.

---

### **i. Additional Enhancements**

You can extend your program with any of the following:

* Find and print the sum of all even and odd numbers separately.
* Replace all negative numbers with zero.
* Check if the matrix is symmetric (i.e., equal to its transpose).
* Add a simple menu so the user can choose which operation to perform.

