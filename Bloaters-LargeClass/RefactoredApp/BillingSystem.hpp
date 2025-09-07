#ifndef BILLINGSYSTEM_HPP
#define BILLINGSYSTEM_HPP

class BillingSystem {
private:
    double outstandingBill = 0.0;

public:
    void addCharge(double amount);
    void payBill(double amount);
    double getOutstandingBill() const;
};

#endif // BILLINGSYSTEM_HPP
