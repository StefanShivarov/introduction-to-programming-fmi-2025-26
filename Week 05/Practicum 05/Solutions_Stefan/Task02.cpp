#include <iostream>

using std::cout;
using std::endl;

const double EPSILON = 1e-10;

void deposit(double& balance, double amount) {
    balance += amount;
}

void withdraw(double& balance, double amount) {
    if (balance - amount < EPSILON) {
        cout << "Not enough balance!";
        return;
    }
    balance -= amount;
}

int main() {
    double balance = 0.0;
    deposit(balance, 49.99);
    std::cout << balance << std::endl;
    withdraw(balance, 55.50);
    std::cout << balance << std::endl;
    withdraw(balance, 40);
    std::cout << balance << std::endl;
}
