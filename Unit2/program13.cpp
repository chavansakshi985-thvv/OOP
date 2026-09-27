#include <iostream>                 // Input/output

class Account                        // Account class
{
private:
    double balance;                  // Account balance

    friend class Auditor;            // Auditor can access private members

public:
    explicit Account(double initialBalance)
        : balance(initialBalance) {} // Constructor
};

class Auditor                        // Auditor class
{
public:
    void inspect(const Account& account) const // Inspect account
    {
        std::cout << "Account Balance: "
                  << account.balance << '\n'; // Access private balance
    }
};

int main()                            // Main function
{
    Account account(5000.0);          // Create Account object
    Auditor auditor;                  // Create Auditor object

    auditor.inspect(account);         // Inspect account

    return 0;                         // End program
}