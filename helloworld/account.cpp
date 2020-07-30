#include <iostream>
#include <iomanip>
using namespace std;

class Account
{
private:
    int accountNumber;
    double balance;

public:
    Account(int no, double b = 0.0);
    int getAccountNumber() const;
    double getBalance() const;
    void setBalance(double balance);
    void credit(double amount);
    void debit(double amount);
    void print() const;
};

Account::Account(int no, double b) : accountNumber(no), balance(b) {}

int Account::getAccountNumber() const
{
    return accountNumber;
}

double Account::getBalance() const
{
    return balance;
}

void Account::credit(double amount)
{
    balance += amount;
}

void Account::debit(double amount)
{
    if (amount <= balance)
    {
        balance -= amount;
    }
    else
    {
        cout << "Amount withdrawn exceed the current balance!" << endl;
    }
}

void Account::print() const
{
    cout << fixed << setprecision(2);
    cout << "A\C no: " << accountNumber << "Balance = Tk" << balance << endl;
}


int main()
{
    Account a1(8111, 99.09);
    a1.print();
    a1.credit(20);
    a1.debit(10);
    a1.print();

    Account a2(8222);
    a2.print();
    a2.setBalance(100);
    a2.credit(20);
    a2.debit(200);
    a2.print();

    return 0;
}
