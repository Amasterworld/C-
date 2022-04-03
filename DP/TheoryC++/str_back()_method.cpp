// str.back predicit output: it is Sanfoundry! 
// because the back() method modified the last char of str then from . ->!

#include <iostream>
#include <string>
using namespace std;
int main ()
{
  std::string str ("Sanfoundry.");
  str.back() = '!';
  std::cout << str << endl;
  return 0;
}