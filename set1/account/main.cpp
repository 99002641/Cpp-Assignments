#include<iostream>
#include "account.h"

Account::Account() :
    m_accNumber(0), m_accName(""), m_balance(0) {
}
Account::Account(int ID, std::string customerName, double balance) :
  m_accNumber(ID), m_accName(customerName), m_balance(balance) {
}
Account::Account(const Account& ref) :
        m_accNumber(ref.m_accNumber), m_accName(ref.m_accName),m_balance(ref.m_balance) {
}
void Account::credit(double amount) {
  m_balance += amount;
}
void Account::debit(double amount) {
  m_balance -= amount;
}
double Account::getBalance() {
    return m_balance;
}
void Account::display() {
    std::cout << m_accNumber << "," << m_accName << "," << m_balance << "\n";
}


