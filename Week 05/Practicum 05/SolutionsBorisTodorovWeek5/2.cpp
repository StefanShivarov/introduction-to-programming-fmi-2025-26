#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void deposit(double& balance, double amount)
{
    balance += amount;
}
void withdraw(double& balance, double amount)
{
    if (amount > balance)
    {
        cout << "Not enough balance!"<<endl;
    }
    else
    {
        balance -= amount;
    }
}
int main()
{
    double balance = 0.0;
    deposit(balance, 49.99);
    std::cout << balance << std::endl;
    withdraw(balance, 55.50);
    std::cout << balance << std::endl;
    withdraw(balance, 40);
    std::cout << balance << std::endl;
}
