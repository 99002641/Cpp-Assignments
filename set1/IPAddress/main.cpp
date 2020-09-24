#include<iostream>
#include<string.h>
#include "ipaddress.h"

IPAddress::IPAddress() :
    ipval("127.0.0.0") {
}
IPAddress::IPAddress(int int1,int int2, int int3, int int4 ) :
    ipval(to_string(int1)+"."+to_string(int2)+"."+to_string(int3)+"."+to_string(int4)) {
}
IPAddress::IPAddress(int i) :
    ipval(to_string(i)+"."+to_string(i)+"."+to_string(i)+"."+to_string(i)) {
}
bool IPAddress::isLoopBack() {
    if (ipval=="127.0.0.1") {
        return true;
    } else {
        return false;
    }
}
void IPAddress::getIPClass() {
    string temp;
    int i=0;
    while (ipval[i]!='.') {
        temp[i]=temp[i]+ipval[i];
        i=i+1;
    }
    int icheck=stoi(temp);
    if(icheck>0 && icheck<=127) {
        IPClass c1 = IPClass::a;
        std::cout<<"IPClass:  "<<char(c1);
    }
    if(icheck>127 && icheck<=191) {
        IPClass c1 = IPClass::b;
        std::cout<<"IPClass:  "<<char(c1);
    }
    if(icheck>191 && icheck<=223) {
        IPClass c1 = IPClass::c;
        std::cout<<"IPClass: "<<char(c1);
    }
    if(icheck>223 && icheck<=240) {
        IPClass c1 = IPClass::d;
        std::cout<<"IPClass:  "<<char(c1);
    }
}
void IPAddress::display() {
    std::cout <<"Your IP Address is: "<<ipval;
}
