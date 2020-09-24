#include<iostream>
#include "color.h"
Color::Color() :
    m_r(0), m_g(0), m_b(0) {
}
Color::Color(int red, int green, int blue) :
    m_r(red), m_g(green), m_b(blue) {
}
Color::Color(string color) {
    cout<<color<<endl;
}
Color::Color(color_t x) {
    switch(x) {
    case red:
        m_r=255;
        m_g=0;
        m_b=0;
        break;
    case blue:
        m_r=0;
        m_g=0;
        m_b=255;
        break;
    case green:
        m_r=0;
        m_g=255;
        m_b=0;
        break;
    case yellow:
        m_r=255;
        m_g=255;
        m_b=0;
        break;
    case black:
        m_r=255;
        m_g=255;
        m_b=255;
        break;
    default:
        cout<<"Undefined Color";
        break;
    }
}
int Color::invert() {
    m_r=255-m_r;
    m_g=255-m_g;
    m_b=255-m_b;
    return(m_r,m_g,m_b);
}
void Color::display() {
    cout<<"The Color composition is as follows: "<<endl;
    std::cout << "Red: "<<m_r << ", Green: " << m_g << ",Blue: " << m_b <<"\n";
}


