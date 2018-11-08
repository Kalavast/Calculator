/* functions used to complete the calculator tool
   Joshua Carter
*/

#include <iostream>
#include <math.h>

using namespace std;


double squareroot ()
{
  double root;
  double r;
  cout << "Enter a number to find squareroot of ";
  cin >> r;
  root = pow (r,0.5);
  cout << root << endl;
}

double squared ()
{
  double square;
  double s;
  cout << "Enter a number to be squared ";
  cin >> s;
  square = s*s;
  cout << square << endl;
}

int power ()
{
  int num = 1;
  int e;
  int b;
  cout << "Enter the base number ";
  cin >> b;
  cout << "Enter the power to be raised to ";
  cin >> e;
  for (int i = 0; i < e; i++)
    {
      num = num * b;
    }
  cout << num << endl;
}

double logarithm ()
{
  double logr;
  int l;
  int c;
  cout << "Choose a log base of 2 or 10 ";
  cin >> c;
  cout << "Enter a number ";
  cin >> l;
  switch (c)
    {
    case 10: logr = log10(l);
      break;
    case 2: logr = log2(l);
      break;
    }
  cout << logr << endl;
}

int main ()
{
  squareroot();
  squared();
  power();
  logarithm();
  return 0;
}
