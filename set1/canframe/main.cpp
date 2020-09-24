#include <iostream>
#include<math.h>
#include<string.h>
#include "account.h"
#include "box.h"
#include "color.h"
#include "customer.h"
#include "image.h"
#include "ipaddress.h"
#include "point.h"


class CANFrame{};
Account::Account() :
    m_accNumber(0), m_accName(""), m_balance(0) {

}
Account::Account(int ID, std::string customerName, double balance) :
  m_accNumber(ID), m_accName(customerName), m_balance(balance) {

}
Account::Account(const Account& ref) :
        m_accNumber(ref.m_accNumber), m_accName(ref.m_accName),
                                              m_balance(ref.m_balance) {

}
void Account::credit(double amount) {
  m_balance += amount;
}
void Account::debit(double amount) {
  //min balance check
  m_balance -= amount;
}
int Account::getM_accNumber() {
  return m_accNumber;
}
std::string Account::getM_accName() {
  return m_accName;
}
double Account::getM_balance() const {
    return m_balance;
}
void Account::display() {
    std::cout << m_accNumber << "," << m_accName << ","
                                         << m_balance << "\n";
}





Box::Box() :
    m_length(0), m_breadth(0), m_height(0) {

}
Box::Box(int length, int breadth, int height) :
  m_length(length),m_breadth(breadth), m_height(height) {

}
Box::Box(int length) :
    m_length(length){
}
Box::Box(const Box& ref) :
        m_length(ref.m_length),m_breadth(ref.m_breadth), m_height(ref.m_height) {

}

void Box::length(int length){
m_length=length;
std::cout<<"Length is: "<<m_length<<endl;
}

void Box::breadth(int breadth){
m_breadth=breadth;
std::cout<<"Breadth is: "<<m_breadth<<endl;
}

void Box::height(int height){
m_height=height;
std::cout<<"height is: "<<m_height<<endl;
}

void volume(int length, int breadth, int height){
int vol=length*breadth*height;
std::cout<<"Volume is: "<<vol<<endl;
}

void Box::display() {
    std::cout << m_length << "," << m_breadth << ","<< m_height<<"\n";
}


Color::Color() :
    m_r(0), m_g(0), m_b(0) {

}
Color::Color(int red, int green, int blue) :
  m_r(red), m_g(green), m_b(blue) {

}
Color::Color(string color){
cout<<"Enter the desired color: ";
cin>>color;
cout<<color<<endl;
}
Color::Color(color_t x){
    switch(x)
    {
        case red:
            cout<<"Red";
            break;
        case blue:
            cout<<"Blue";
            break;
        case green:
            cout<<"Green";
            break;
        case yellow:
            cout<<"Yellow";
            break;
        case black:
            cout<<"Black";
            break;
        default:
            cout<<"Undefined Color";
            break;
    }
}
void Color::invert() {
    int neg = 0xFFFFFF - m_r*m_g*m_b;
    neg = (0xFFFFFF - m_r*m_g*m_b) | 0xFF000000;
    cout<<"The Color has been inverted "<<endl;
    cout<<neg;
}
void Color::display() {
    cout<<"The Color composition is as follows: "<<endl;
    std::cout << "Red: "<<m_r << ", Green: " << m_g << ",Blue: " << m_b <<endl;
}

Customer::Customer() :
    m_custId(0), m_phone(0), m_type(0),m_custName("none"),m_balance(0) {

}
Customer::Customer(int ID,int phone, std::string n, double balance) :
  m_custId(ID), m_phone(phone), m_custName(n),m_balance(balance) {

}

Customer::Customer(int ID, int phone, std::string Name) :
    m_custId(ID), m_phone(phone), m_custName(Name) {
}


Customer::Customer(const Customer& ref) :
        m_custId(ref.m_custId), m_phone(ref.m_phone), m_type(ref.m_type),m_custName(ref.m_custName),m_balance(ref.m_balance) {

}
void Customer::credit(AccountType t) {
  switch(t)
  {
  case savings:
    cout<<"Credit money to Savings Account..."<<endl;
  case current:
    cout<<"Credit money to Current Account..."<<endl;
  }
}
void Customer::makecall(int call) {
  m_phone = call;
  std::cout<<"Making call for: "<<m_phone<<endl;
}
int Customer::getBalance() {
  return m_balance;
}

void Customer::display() {
    std::cout << m_custId << "," << m_phone << ","<<m_type<<","<<m_custName<<","<< m_balance << "\n";
}



Image::Image() :
    m_x(0), m_y(0), m_width(0), m_height(0) {

}
Image::Image(int r, int l, int u, int d) :
  m_x(r), m_y(l), m_width(u), m_height(d) {

}
Image::Image(const Image& ref) :
        m_x(ref.m_x), m_y(ref.m_y),m_width(ref.m_width), m_height(ref.m_height) {

}
void Image::move(int quadrant, int position1, int position2) {
  if(quadrant==1){
    m_x=position1;
    m_y=position2;
    std::cout<< "Image has been moved to first quadrant and now the position is" << m_x <<","<< m_y ;
    }
    else if(quadrant==2){
    m_x=position1;
    m_y=position2;
    std::cout<< "Image has been moved to second quadrant and now the position is" << m_x<<"," << m_y ;
    }
    if(quadrant==3){
    m_x=position1;
    m_y=position2;
    std::cout<< "Image has been moved to third quadrant and now the position is" << m_x <<"," << m_y ;
    }
    if(quadrant==4){
    m_x=position1;
    m_y=position2;
    std::cout<< "Image has been moved to forth quadrant and now the position is" << m_x<< "," << m_y ;
    }

}
void Image::scale(int r, int l) {
  std::cout << r << l;
}
int Image::resize(int number1, int number2) {
  m_x=m_x+number1;
  m_y=m_y+number2;
  std::cout<< m_x <<"," << m_y;
}

void Image::display() {
    std::cout << m_x << "," << m_y << "," << m_width << ","<< m_height<<"\n";
}


IPAddress::IPAddress() :
    ipval("127.0.0.0") {

}

IPAddress::IPAddress(int int1,int int2, int int3, int int4 ) :
 ipval(to_string(int1)+"."+to_string(int2)+"."+to_string(int3)+"."+to_string(int4)){

}

IPAddress::IPAddress(int i) :
    ipval(to_string(i)) {
}



bool IPAddress::isLoopBack(std::string s1) {
    if (s1=="127.0.0.1")
    {
        std::cout<<"true"<<endl;
    }
    else{
        std::cout<<"false"<<endl;
    }
}
void IPAddress::getIPClass(std::string s){
string temp;
int i=0;
while (s[i]!='.')
{
    temp[i]=temp[i]+s[i];
    i=i+1;
}
int icheck=stoi(temp);
if(icheck>0 && icheck<127)
{
IPClass c1= IPClass::a;
std::cout<<"IPClass: a "<<char(c1);
}
if(icheck>127 && icheck<191)
{
IPClass c1= IPClass::b;
std::cout<<"IPClass: b "<<char(c1);
}
if(icheck>191 && icheck<223)
{
IPClass c1= IPClass::c;
std::cout<<"IPClass: c "<<char(c1);
}
if(icheck>223 && icheck<240)
{
IPClass c1= IPClass::d;
std::cout<<"IPClass: d "<<char(c1);
}

}
void IPAddress::display() {
    std::cout <<"Your IP Address is:"<<ipval;
}


Point::Point():
    m_x(0), m_y(0) {
}
Point::Point(int a, int b):
    m_x(a),m_y(b) {
}
Point::Point(const Point& ref) :
    m_x(ref.m_x), m_y(ref.m_y) {
}
void Point::distanceFromOrigin(int a,int b) {
    int d =sqrt(a^2 + b^2);
    std::cout << "distance from Origin is" << d << "\n";
}
void Point::quadrant(Quadrant x) {
    switch(x)
    {
        case q1:
            cout<<"First Quadrant";
            break;
        case q2:
            cout<<"Second Quadrant";
            break;
        case q3:
            cout<<"Third Quadrant";
            break;
        default:
            cout<<"Fourth Quadrant";
            break;
    }

}

void Point::isOrigin(int a,int b) {
    if(a==0 && b==0)
        std::cout << "Point is on the Origin";
}

void Point::isOnXAxis(int a,int b) {
    if(b==0)
        std::cout << "Point lies on X axis";
}

void Point::isOnYAxis(int a,int b) {
    if(a==0)
        std::cout << "Point lies on Y axis";
}

void Point::display() {
    std::cout << m_x << "," << m_y << "\n";
}


int main()
{
   return 0;
}
