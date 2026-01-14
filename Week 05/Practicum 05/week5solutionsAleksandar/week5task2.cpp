#include <iostream>
using namespace std;

void deposit(double& balance, double amount) {
    balance += amount;
    cout << balance << endl;
}
void withdraw(double& balance, double amount) {
    if (balance >= amount) { balance -= amount; }
    else {  cout << "Not enough balance!" << endl;}
    cout << balance << endl;
}
int main() {
    double balance = 0.0;
    deposit(balance, 49.99);
    withdraw(balance, 55.50);
    withdraw(balance, 40);
}
