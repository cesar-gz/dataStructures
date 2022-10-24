// reviewing basic OOP syntax and classes
#include <iostream>
#include <cstdlib> //for random number generation
using namespace std;

class BankAccount{
    private:
        double balance;         // account balance
    public:
        BankAccount(double openingBalance){     // our constructor
            balance = openingBalance;
        }

        void deposit(double amount){
            // makes deposit
            balance += amount;
        }

        void withdraw(double amount){
            // withdraw the amount
            balance -= amount;
        }

        void display(){
            // print the balance
            cout << "You have $" << balance << " in your bank account \n" << endl;
        }
}; // end of Bank Account class

int main(){
    BankAccount savingsAccount(100000.00);  //create an account

    cout << "\nBefore transaction, ";
    savingsAccount.display();

    double randomAmount = rand();
    savingsAccount.deposit(randomAmount);
    cout << "After deposit, ";
    savingsAccount.display();

    randomAmount = rand();
    savingsAccount.withdraw(randomAmount);
    cout << "After withdraw, ";
    savingsAccount.display();

    return 0;
}