// MatrixExplorer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
const int MAX = 10;
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void transpose(int matrix[][MAX], int n)
{
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            if (i < j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
}
void rotateMatrix(int matrix[][MAX], int n)
{
    transpose(matrix, n);
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n / 2;j++)
        {
            swap(matrix[i][j], matrix[i][n - j - 1]);
        }
    }
}
int mainDiagonalSum(const int matrix[][MAX], int n)
{
    int sum = 0;
    for (int i = 0, j = 0;i < n;i++, j++)
    {
        sum += matrix[i][j];
    }
    return sum;
}
int secondaryDiagonalSum(const int matrix[][MAX], int n)
{
    int sum = 0;
    for (int i = n-1, j = 0;i >=0;i--, j++)
    {
        sum += matrix[i][j];
    }
    return sum;
}
int getMin(const int matrix[][MAX], int n)
{
    int min=matrix[0][0];
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
            }
        }
    }
    return min;
}
int getMax(const int matrix[][MAX], int n)
{
    int max = matrix[0][0];
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
        }
    }
    return max;
}
void printRowSums(const int matrix[][MAX], int n)
{
    for (int i = 0;i < n;i++)
    {
        int sum = 0;
        for (int j = 0;j < n;j++)
        {
            sum += matrix[i][j];
        }
        cout << "Sum of row " << i << ": " << sum<<endl;
    }
}
void printColSums(const int matrix[][MAX], int n)
{
    for (int i = 0;i < n;i++)
    {
        int sum = 0;
        for (int j = 0;j < n;j++)
        {
            sum += matrix[j][i];
        }
        cout << "Sum of col " << i << ": " << sum << endl;
    }
}
int sumAll(const int matrix[][MAX], int n)
{
    int sum=0;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}
void setMatrix(int matrix[][MAX],int n)
{
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            int x = 0;
            cin >> x;
            matrix[i][j]=x;
        }
    }
}
void printMatrix(int matrix[][MAX], int n)
{
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            cout<<matrix[i][j]<< " ";
        }
        cout << endl;
    }
}
int main()
{
    int n = 0;
    cout << "Enter size of matrix: ";
    cin >> n;
    int matrix[MAX][MAX];
    cout << "Enter matrix" << endl;
    setMatrix(matrix, n);
    char input;
    cout << "Enter command:"<<endl;
    cout << "a - print matrix; b - sum all; c - print sum of rows; d - print sum of collumns"<<endl
         << "e - get min; f - get max; g - sum of main diagonal; h - sum of secondary diagonal"<<endl
         << "i - transpose and print; j - rotate and print; z - end program"<<endl;
    
    cout << "Enter input: ";
    cin >> input;
    while (input != 'z')
    {
        switch (input)
        {
            case 'a':
                printMatrix(matrix, n);
                break;
            case 'b':
                cout <<"Sum of all: "<< sumAll(matrix, n) << endl;
                break;
            case 'c':
                printRowSums(matrix, n);
                break;
            case 'd':
                printColSums(matrix, n);
                break;
            case 'e':
                cout <<"Min: "<<getMin(matrix, n) << endl;
                break;
            case 'f':
                cout <<"Max: "<< getMax(matrix, n) << endl;
                break;
            case 'g':
                cout << "Sum of main diagonal: " << mainDiagonalSum(matrix, n) << endl;
                break;
            case 'h':
                cout << "Sum of secondary diagonal: " << secondaryDiagonalSum(matrix, n) << endl;
                break;
            case 'i':
                transpose(matrix, n);
                printMatrix(matrix, n);
                break;
            case 'j':
                rotateMatrix(matrix, n);
                printMatrix(matrix, n);
                break;
            default:
                cout << "Unrecognized command try again";
                break;
        }
        cout << "Enter input: ";
        cin >> input;
    }
}
