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
  return root;
}

double squared ()
{
  double square;
  double s;
  cout << "Enter a number to be squared ";
  cin >> s;
  square = s*s;
  return square;
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
  return num;
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
  return logr;
}

int main ()
{
  cout << squareroot() << endl;
  cout << squared() << endl;
  cout << power() << endl;
  cout << logarithm() << endl;
  return 0;
}
