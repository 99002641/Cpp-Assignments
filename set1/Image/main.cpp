#include<iostream>
#include "image.h"
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
    std::cout<< "Image has been moved to first quadrant and now the position is " << m_x <<","<< m_y ;
    }
    else if(quadrant==2){
    m_x=position1;
    m_y=position2;
    std::cout<< "Image has been moved to second quadrant and now the position is " << m_x<<"," << m_y ;
    }
    if(quadrant==3){
    m_x=position1;
    m_y=position2;
    std::cout<< "Image has been moved to third quadrant and now the position is " << m_x <<"," << m_y ;
    }
    if(quadrant==4){
    m_x=position1;
    m_y=position2;
    std::cout<< "Image has been moved to forth quadrant and now the position is " << m_x<< "," << m_y ;
    }
}
void Image::scale(int r, int l) {
  m_width=r;
  m_height=l;
  std::cout <<m_width<<","<<m_height;
}
int Image::resize(int number1, int number2) {
  m_x=m_x+number1;
  m_y=m_y+number2;
  std::cout<< m_x <<"," << m_y;
}
void Image::display() {
    std::cout << m_x << "," << m_y << "," << m_width << ","<< m_height<<"\n";
}


