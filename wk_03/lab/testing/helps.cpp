#include "help.h"
#include <iostream>

hello::hello(int x, int y)
{
  this->x=x;
  this->y=y;
};
void hello::getNums()
{
  std::cout<<"This is the value of x: "<< x<< std::endl;
  std::cout<<"This is the value of y: "<< y;
}
