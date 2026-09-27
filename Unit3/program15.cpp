#include <iostream>  // Input/output
#include <string>    // String library

class Payment {
public:
    // Pure virtual function
    virtual void pay(double amount) const = 0;

    // Virtual destructor
    virtual ~Payment() = default;
};

class CardPayment : public Payment {
public:
    // Implement pay()
    void pay(double amount) const override {
        std::cout << "Paid Rs. " << amount << " using card\n";
    }
};

class UpiPayment : public Payment {
public:
    // Implement pay()
    void pay(double amount) const override {
        std::cout << "Paid Rs. " << amount << " using UPI\n";
    }
};

class NetBankingPayment : public Payment {
public:
    // Implement pay()
    void pay(double amount) const override {
        std::cout << "Paid Rs. " << amount << " using net banking\n";
    }
};

// Process payment using base reference
void processPayment(const Payment& payment, double amount) {
    payment.pay(amount);
}

int main() {
    CardPayment card;              // Card object
    UpiPayment upi;                // UPI object
    NetBankingPayment netBanking;  // Net banking object

    processPayment(card, 1250.0);
    processPayment(upi, 750.0);
    processPayment(netBanking, 500.0);

    return 0;  // End program
}