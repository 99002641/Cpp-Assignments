#include<iostream>
#include<string.h>
#include "customer.h"
Customer::Customer() :
    m_custId(0), m_phone(0), m_type(0),m_custName("none"),m_balance(0) {

}
Customer::Customer(int id,int ph, std::string n, double bal) :
  m_custId(id), m_phone(ph), m_custName(n),m_balance(bal) {

}

Customer::Customer(int id, int ph, std::string name) :
    m_custId(id), m_phone(ph), m_custName(name) {
}


Customer::Customer(const Customer& ref) :
        m_custId(ref.m_custId), m_phone(ref.m_phone), m_type(ref.m_type),m_custName(ref.m_custName),m_balance(ref.m_balance) {

}
int Customer::credit(double cred, AccountType t) {

  switch(t)
  {
  case prepaid:
    m_balance=m_balance+cred;
    return(m_balance);
  case postpaid:
    m_balance=m_balance+cred;
    return(m_balance);
  }
}
void Customer::makecall(int call) {

  std::cout<<"Making call for: "<<call<<" from "<<m_phone<<"\n";
}
int Customer::getBalance() {
  return m_balance;
}

void Customer::display() {
    std::cout << m_custId << "," << m_phone<<","<<m_custName<<","<< m_balance << "\n";
}


