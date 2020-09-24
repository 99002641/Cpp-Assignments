#include <iostream>
#include "box.h"

using namespace std;
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
int Box::length(){
return (m_length);
}
int Box::breadth(){
return (m_breadth);
}
int Box::height(){
return (m_height);
}
int Box::volume(){
int vol=m_length*m_breadth*m_height;
return(vol);
}
void Box::display() {
    std::cout << m_length << "," << m_breadth << ","<< m_height<<"\n";
}




