#include "Myclass.h"
#include <iostream>
#include <string>
using namespace std;

void Myclass::myPrint() const 
{
  cout <<"Hello"<<endl;

};

int main()
{
  const Myclass obj;
  obj.myPrint();

  return 0;
}