#include<iostream>
#include <math.h>
#include<cstdlib>
#include<stdlib.h>
#include <limits>
using namespace std;

/*
Authors: Aziz Aldawk, Ross Youngs, Joshua Carter, Matthew Janosik.
Date:12/13/2018
Class:INFO-I450
*/


struct Index
{
        int data;
        Index* linkf;
        Index* linkb;
};
Index *head = NULL;
Index *tail = new Index;
Index *current = NULL;
Index *save = NULL;

//void sorting();
//oid FirstVarStat();
float Addition(float num1, float num2);
float Multiplication(float num1, float num2);
float Subtraction(float num1, float num2);
float Division();
double squareroot();
double squared();
int power(); //Joshua's functions
double logarithm(); //Joshua's function.

void Menu(); // Aziz's functions
void CreatList();// Matt's functions.

void sorting();
void DisplayList();
void FirstVarStat();
void Median(int);
void Mode();
void StDeviation(double, int);

void AdditionAdapter();// Ross's function.
void MultiplicationAdapter();// Ross's function
void SubtractionAdapter();// Ross's function
void DivisionAdapter();
  /*
The main where program or complie start and run
the functions.
usually has nothing on it, only the menu.
*/
int main(){
        Menu();
        //call function for menu...
        system("clear");
 }

/*================= Menu Function ===============
This function supposed to be chose what the user need
and  which the function.
For example, if user want adding, he/she
must chose number 1 to apply adding functing
and can use it.
if user want to exit, he/she may select zero
to stop the loop and exit.
==============================================*/
//Aziz's functions
void Menu(){

        int number;
        do{
                cout << "Creat list press <1>" << endl
                     << "Sort list press <2>" << endl
                     << "Find First Varible Statistics <3>" << endl
                     << "Display List <4>" << endl
                     << "Addition press <5>" << endl
                     << "Multiplication press  <6>" << endl
                     << "Subtraction press  <7>" << endl
                     << "Divison press  <8>" << endl
                     << "Squareroot press  <9>" << endl
                     << "Squared press  <10>" << endl
                     << "Power press  <11>" << endl
                     << "logarithm press  <12>" << endl
                        << "Quit press <0>" << endl;
                // The outputs ask user what she/he wants on menus options..
                cin >> number;
                system("clear");
                switch (number)
                {
                case 1:
                //system("clear");
                      CreatList();
                break;

                case 2:
                            current = head->linkf;
                            while (current->linkf != NULL)
                        {
                            current = current->linkf;
                           save = head->linkf;
                           sorting();
                        }
                           DisplayList();
                break;
                case 3:
                             current = head->linkf;
                             while (current->linkf != NULL)
                  {
                            current = current->linkf;
                            save = head->linkf;
                            sorting();
                  }
                FirstVarStat();
                break;
                case 4:
                  cout << "List Displayed " << endl;
                      DisplayList();
                break;
                case 5:
                 AdditionAdapter();
               break;
                case 6:
                MultiplicationAdapter();
                break;
                case 7:
                SubtractionAdapter();
               break;
               case 8:
                DivisionAdapter();
                break;
                case 9:
                squareroot();
                break;
                 case 10:
                     squared();
                 break;
                 case 11:
                        power();
                        break;
                case 12:
                         logarithm();
                        break;
        default:
                        cout << "Quitting from program" << endl;
        exit(0); // Default, if user enter other number is not on the menu.
                }// menu funciton has been completed and worked correctly.
                // default to a void of any bugs or error.

        } while (number != 0); // assume user select zero, loop will stop and exit.

}

// function's Matt
void CreatList() {
        double num = 0;
        cout << "Enter Numbers into the list and use 0 to stop entering numbers" << endl;
        do {

                while (!(cin >> num)) {
                        system("clear");   //change to system ("clear"); !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                        cout << "Invalide input!" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Enter a number again please. Enter 0 to exit." << endl;
                        current = head;
                        DisplayList();

                }
                if (num > 0)
                {

                        if (head == NULL) {
                                head = new Index;
                                head->linkf = tail;
                                tail->linkb = head;
                                tail->data = num;
                        }
                        else {
                                tail->linkf = new Index;
                                tail->linkf->linkb = tail;
                                tail = tail->linkf;
                                tail->data = num;
                                tail->linkf = NULL;
                        }
                }
        } while (num != 0);
        tail->linkf = NULL;
}
//Matt functions.
// this functions does a _________ Sort in order to sort the function
void sorting()
{

        while (save->data != current->data || save->linkb->data != current->linkb->data) {

                if (current->data < save->data && save->linkf->data == current->data)
                {
                        save->linkf = current->linkf;// current->link ?= NULL
                        current->linkf = save;
                        current->linkb = save->linkb;
                        current->linkb->linkf = current;
                        save->linkb = current;
                        if (save->linkf == NULL)
                        {
                                return;
                        }
                        save->linkf->linkb = save;
                        current = save;
                        return;
                }

                if (current->data < save->data && current->linkf != NULL)
                {
                        current->linkb->linkf = current->linkf;
                        current->linkf->linkb = current->linkb;

                        save->linkb->linkf = current;
                        current->linkb = save->linkb;

                        save->linkb = current;
                        current = save; //current = current->linf
                        save->linkb->linkf = save;
                        return;
                }

                if (current->data < save->data && current->linkf == NULL)
                {
                        tail = current->linkb;
                        current->linkb->linkf = NULL;
                        current->linkf = save;
                        save->linkb->linkf = current;
                        current->linkb = save->linkb;
                        save->linkb = save->linkb->linkf;
                        return;
                }
                save = save->linkf;
        }

}
//Matt's functions.
// This function finds mean,median,mode and range and gives the answer to the user.
void FirstVarStat()
{
        //int num = 0;
        double num1 = 0;
        //int num2 = 0;
        int quantity = 0;
        //int set[30] = { 0 };
        //int tally[30] = { 0 };
        //bool mode = true;


        current = head;
        do {
                current = current->linkf;
                quantity = quantity + 1;
                num1 = current->data + num1;
        } while (current->linkf != NULL);
        num1 = num1 / quantity;
        cout << "Quantity " << quantity << endl;
        cout << "Mean  " << num1 << endl;
        StDeviation(num1, quantity);
        Median(quantity);
        Mode();

        // FInd range
        num1 = tail->data - head->linkf->data;
        cout << "Range  " << num1 << endl;
}

void Median(int quantity)
{
        int num = 0;
        double num1 = 0;
        double num2 = 0;
        //finding median
        if (quantity % 2 == 0) // if even amout of numbers
        {
                num = quantity / 2;
                save = head;
                for (int i = 0; i != num; i++) {
                        save = save->linkf;
                }
                num2 = save->data;
                num1 = save->linkf->data;
                cout << "Median  " << (num2 + num1) / 2 << endl;

        }
        else// if (num % 2 > 1) or an odd man out
        {
                num = quantity / 2;
                save = head->linkf;
                for (int i = 0; i != num; i++) {
                        save = save->linkf;
                }
                num2 = save->data;
                cout << "Median  " << num2 << endl;
        }
        //Find Quartiles
        if (quantity % 4 == 0)
        {
                num = (quantity / 4);
                current = head->linkf;
                for (int i = 0; i != num; ++i) {
                        current = current->linkf;
                }
                num1 = current->data;
                num2 = current->linkb->data;
                cout << "Q1  " << (num2 + num1) / 2 << endl;

                current = tail;
                for (int i = 0; i != num; ++i) {
                        current = current->linkb;
                }
                num1 = current->data;
                num2 = current->linkf->data;
                cout << "Q3  " << (num2 + num1) / 2 << endl;
        }
        else
        {
                num = (quantity / 4);
                current = head->linkf;
                for (int i = 0; i != num; ++i) {
                        current = current->linkf;
                }
                num1 = current->data;
                cout << "Q1  " << num1 << endl;

                current = tail;
                for (int i = 0; i != num; ++i) {
                        current = current->linkb;
                }
                num1 = current->data;
                cout << "Q3  " << num1 << endl;
        }

}
void Mode()
{
        int num = 0;
        int num2 = 0;
        int quantity = 0;
        double set[30] = { 0 };
        int tally[30] = { 0 };
        bool mode = true;

        current = head->linkf;
        num = 0;
        set[0] = current->data;
        tally[0] = 1;
        do { //part 1: make a tally of all numbers
                current = current->linkf;
                if (set[num] != current->data) // 1,1,2,2,3,3,4,4
                {
                        num = num + 1;
                        set[num] = current->data;
                }
                tally[num] = tally[num] + 1;
        } while (current->linkf != NULL);

        num = 1;// set the couter to the second number in the list
                        // num2 will start as the second number in the list
        do {// part 2: Find which tally is biggest and if they are both
                if (tally[num2] == tally[num]) {
                        mode = false;
                }
                if (tally[num2] < tally[num]) {
                        num2 = num;
                        mode = true;
                }
                num = num + 1;//
        } while (tally[num] != 0);

        if (mode == true)//Check to see if mode id true
        {
                cout << "Mode  " << set[num2] << endl;
                //cout << "num  " << num2 << endl;
                // this is only if you want to check wich place the num is from
        }
        else
        {
                cout << "Mode does not exist" << endl;
        }
}
void StDeviation(double mean, int quantity)
{
        double num1 = 0;
        double num2 = 0;
        current = head;
        do {
                current = current->linkf;
                num1 = (current->data - mean);
                num1 = pow(num1, 2);
                num2 = num2 + num1;
                //sqrt() square roots anything within the middle pow()
        } while (current->linkf != NULL);

        num1 = num2 / (quantity - 1);// sample
        num2 = num2 / (quantity);//pop

        num1 = pow(num1, .5);//sample
        num2 = pow(num2, .5);//pop
        cout << "Sample Standard Div " << num1 << endl;
        cout << "Poplulation Standard Div " << num2 << endl;
}
void DisplayList()
{
        current = head;
        do {
                current = current->linkf;
                cout << current->data << endl;
        } while (current->linkf != NULL);
}

//Ross function's
void AdditionAdapter(){

        float num1, num2, result;
        //set numbers to 0
        num1 = num2 = 0;
        //inputs numbers
        cout << "Please enter a first number: ";
        while (!(cin >> num1))
        {
                cout << "Invalide input!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter a number again please." << endl;
        }
        cout << "Please enter a second Number: ";
        while (!(cin >> num2))
        {
                cout << "Invalide input!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter a number again please." << endl;
        }

        //calls addition function
        result = Addition(num1, num2);
        //use this function if you want the numbers to be input after the function is called.
        //result=Addition();

cout<<endl;
        cout<<""<<num1<<"+"<<num2<<"="<<result << endl;
        cout<<endl;

}
//Ross's functions
float Addition(float num1, float num2)
{
        int sum;
        sum = num1 + num2;
        return sum;
}
/*use this function if you want the numbers to be input after the function is called.
float Addition()
{
float num1,num2,sum;
//initialize all numbers
num1=num2=sum=0;
cout << "Please enter a Number: ";
cin >> num1;
cout << "Please enter a second Number: ";
cin >> num2;
sum=num1+num2;
return sum;
}*/
//Ross's Functions.
void MultiplicationAdapter(){

        float num1, num2, result;
        //set numbers to 0
        num1 = num2 = 0;
        //inputs numbers
        cout << "Please enter a first number: ";
        while (!(cin >> num1))
        {
                        cout << "Invalide input!" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Enter a first number again please." << endl;
        }
        cout << "Please enter a second Number: ";
        while (!(cin >> num2))
        {
                        cout << "Invalide input!" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Enter a second number again please." << endl;
        }
        //calls Multiplication function
        result = Multiplication(num1, num2);
        //use this function if you want the numbers to be input after the function is called.
        //result=Multiplication();


        cout<<endl;
                cout<<""<<num1<<"*"<<num2<<"="<<result << endl;
                cout<<endl;
}

//Ross function's
float Multiplication(float num1, float num2)
{
        int sum;
        //multiplies the numbers and returns sum.
        sum = num1*num2;
        return sum;
}
/*use this function if you want the numbers to be input after the function is called.
float Multiplication()
{
float num1,num2,sum;
//initialize all numbers
num1=num2=sum=0;
cout << "Please enter a Number: ";
cin >> num1;
cout << "Please enter a second Number: ";
cin >> num2;
sum=num1+num2;
return sum;
}*/
//Ross's functions.
void SubtractionAdapter(){
        float num1, num2, result;
        //set numbers to 0
        num1 = num2 = 0;
        //inputs numbers
        cout << "Please enter a first number: ";
        while (!(cin >> num1))
        {
                        cout << "Invalide input!" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Enter a first number again please." << endl;
        }
        cout << "Please enter a second Number: ";
        while (!(cin >> num2))
        {
                        cout << "Invalide input!" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Enter a second number again please." << endl;
        }

        //calls Subtraction function
        result = Subtraction(num1, num2);
        //use this function if you want the numbers to be input after the function is called.
        //result=Subtraction();


                cout<<endl;
                        cout<<""<<num1<<"-"<<num2<<"="<<result << endl;
                        cout<<endl;

}

//Ross's Functions.
float Subtraction(float num1, float num2)
{
        int sum;
        //does subtraction arithmetic, and gives sum.
        sum = num1 - num2;
        return sum;
}
/*use this function if you want the numbers to be input after the function is called.
float Subtraction()
{
float num1,num2,sum;
//initialize all numbers
num1=num2=sum=0;
cout << "Please enter a Number: ";
cin >> num1;
cout << "Please enter a second Number: ";
cin >> num2;
sum=num1-num2;
return sum;
}*/

void DivisionAdapter(){
float result;
result=0;

//calls Multiplication function
result=Division();


//cout << result<<endl;

}

float Division(){
        float num1,num2,Quoitent;
        //initialize all numbers
        num1=num2=Quoitent=0;
        cout << "Please enter a first number: ";
        while (!(cin >> num1))
        {
                cout << "Invalide input!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter a first number again please." << endl;
        }
        cout << "Please enter a second Number: ";
        while (!(cin >> num2))
        {
                cout << "Invalide input!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter a second number again please." << endl;
        }
        Quoitent=num1/num2;
                                cout<<endl;
                                cout<<""<<num1<<"\u00F7"<<num2<<"="<<Quoitent<<endl;
                                cout<<endl;
        return Quoitent;
}

//Joshua's Functions


double squareroot(){

    double root;
      double r;
      cout << "Enter a number to find squareroot of ";
      while (!(cin >> r))
        {
          cout << "Invalide input!" << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Enter a number again please." << endl;
        }
      root = pow(r, 0.5);
      cout << endl;
      cout << "" << "√" << r << " = " << root << endl;
    cout << endl;
}


double squared(){

    double square;
      double s;
      cout << "Enter a number to be squared ";
      while (!(cin >> s))
        {
          cout << "Invalide input!" << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Enter a number again please." << endl;
        }
      square = s*s;
      cout << endl;
      cout << "" << s << "²" << " = " << square << endl;
    cout << endl;
}


int power(){

    int num = 1;
      int e;
      int b;
      cout << "Enter the base number ";
      while (!(cin >> b))
        {
          cout << "Invalide input!" << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Enter a number again please." << endl;
        }
      cout << "Enter the power to be raised to ";
      while (!(cin >> e))
        {
          cout << "Invalide input!" << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Enter a number again please." << endl;
        }
      for (int i = 0; i < e; i++)
        {
          num = num * b;
        }
      cout << endl;
      cout << "" << b << " raised to " << e << " power "<< " = " << num << endl;
      cout << endl;

}



double logarithm()
{
    double logr;
      int l;
      int c;
      cout << "Choose a log base of 2 or 10: ";
      while (!(cin >> c && c == 2 || c == 10))
        {
          cout << "Invalide input!" << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Enter a number again please." << endl;
        }
      cout << "Enter a number ";
      while (!(cin >> l))
        {
          cout << "Invalide input!" << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Enter a number again please." << endl;
        }
      switch (c)
        {
        case 10: logr = log10(l);
          cout << endl;
          cout << "" << "Log base " << c << " of " << l << " = " << logr << endl;
          cout << endl;
          break;
        case 2: logr = log2(l);
          cout << endl;
          cout << "" << "Log base " << c << " of " << l << " = " << logr << endl;
          cout << endl;
          break;
    }
}
