#include "BillingSystem.hpp"

void BillingSystem::addCharge(double amount) {
    outstandingBill += amount;
}

void BillingSystem::payBill(double amount) {
    outstandingBill -= amount;
}

double BillingSystem::getOutstandingBill() const {
    return outstandingBill;
}
