#include<iostream>
#include <math.h>
#include<cstdlib>
using namespace std;

/*
Authors: Aziz Aldawk, Ross Youngs, Joshua Carter, Matthew Janosik.
Purpose:
Date:
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

void sorting();
void FirstVarStat();
float Addition(float num1, float num2);
float Multiplication(float num1, float num2);
float Subtraction(float num1, float num2);
float Division();
double squareroot();
double squared();
int power();
double logarithm();

void Menu(); // Aziz's functions
void CreatList();// Matt's functions.
void Addition1();// Ross's function.
void Multiplication1();// Ross's function
void Subtraction1();// Ross's function
void Divison1();
void squareroot1();// Joshua's function
void squared1();// Joshua's function
void power1();// Joshua's functions
void logarithm1();// Joshua's function.
/*
The main where program or complie start and run
the functions.
usually has nothing on it, only the menu.
*/
int main(){

	Menu();
	//call function for menu...
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
			<< "Addition press <2>" << endl
			<< "Multiplication press  <3>" << endl
			<< "Sub press  <4>" << endl
			<< "Divison press  <5>" << endl
			<< "Squareroot press  <6>" << endl
			<< "Squared press  <7>" << endl
			<< "Power press  <8>" << endl
			<< "logarithm press  <9>" << endl
			<< "Quite press <0> " << endl;
		// The outputs ask user what she/he wants on menus options..
		cin >> number;
		switch (number)
		{
		case 1:
			CreatList();
			break;
		case 2:
			Addition1();
			break;

		case 3:
			Multiplication1();
			break;
		case 4:
			Subtraction1();
			break;
		case 5:
			Divison1();
			break;
                case 6:
			squareroot1();
			break;
		case 7:
			squared1();
			break;
		case 8:
			power1();
			break;
		case 9:
			logarithm1();
			break;
        default:
			cout << "Quitting from program" << endl;
        exit(0); // Default, if user enter other number is not on the menu.
		}// menu funciton has been completed and worked correctly.
		// default to a void of any bugs or error.

	} while (number != 0); // assume user select zero, loop will stop and exit.

}

// function's Matt
void CreatList(){

	/////////////// this should be in  create list
	int num = 0;
	cout << "Enter numbers or press 0 to ";
	do {
		cout << "Enter Number" << endl;
		cin >> num;
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
			}
		}
	} while (num != 0);
	tail->linkf = NULL;


	current = head->linkf;
	while (current->linkf != NULL)
	{
		current = current->linkf;
		save = head->linkf;
		sorting();

	}


	////////////this should be in the option First Variable Statistics in the menu
	FirstVarStat();

	current = head;
	do {
		current = current->linkf;
		cout << current->data << endl;
	} while (current->linkf != NULL);



}
//Matt functions.
// this functions does a _________ Sort in order to sort the function
void sorting()
{

	while (save->data != current->data || save->linkb->data != current->linkb->data){

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
	int num = 0;
	double num1 = 0;
	int num2 = 0;
	//int num3 = 0;
	int set[30] = { 0 };
	int tally[30] = { 0 };
	bool mode = true;
	current = head;
	do {
		current = current->linkf;
		num = num + 1;
		num1 = current->data + num1;
	} while (current->linkf != NULL);
	num1 = num1 / num;
	cout << "Mean  " << num1 << endl;

	//finding median
	if (num % 2 == 0) // if even amout of numbers
	{
		num = num / 2;
		save = head;
		for (int i = 0; i != num; i++) {
			save = save->linkf;
		}
		num2 = save->data;
		num1 = save->linkf->data;
		cout << "Median  " << (num2 + num1) / 2 << endl;

		if (num % 2 == 0)
		{
			num = (num / 2);
			current = save;
			for (int i = 0; i != num; ++i) {
				current = current->linkb;
			}
			num1 = current->data;
			num2 = current->linkb->data;
			cout << "Q1  " << (num2 + num1) / 2 << endl;


			current = save->linkf;
			for (int i = 0; i != num; ++i) {
				current = current->linkf;
			}
			num1 = current->data;
			num2 = current->linkb->data;
			cout << "Q2  " << (num2 + num1) / 2 << endl;
		}
		else
		{
			num = (num / 2);
			current = save;
			for (int i = 0; i != num; ++i) {
				current = current->linkb;
			}
			num1 = current->data;
			cout << "Q1  " << num1 << endl;

			current = save->linkf;
			for (int i = 0; i != num; ++i) {
				current = current->linkf;
			}
			num1 = current->data;
			cout << "Q2  " << num1 << endl;
		}
	}
	// median
	else// if (num % 2 > 1)
	{
		num = num / 2;
		save = head->linkf;
		for (int i = 0; i != num; i++) {
			save = save->linkf;
		}
		num2 = save->data;
		cout << "Median  " << num2 << endl;


		if (num % 2 == 0)
		{
			num = (num / 2);
			current = save;
			for (int i = 0; i != num; ++i) {
				current = current->linkb;
			}
			num1 = current->data;
			num2 = current->linkb->data;
			cout << "Q1  " << (num2 + num1) / 2 << endl;


			current = save->linkf;
			for (int i = 0; i != num; ++i) {
				current = current->linkf;
			}
			num1 = current->data;
			num2 = current->linkb->data;
			cout << "Q2  " << (num2 + num1) / 2 << endl;
		}
		else
		{
			num = (num / 2);
			current = save;
			for (int i = 0; i != num; ++i) {
				current = current->linkb;
			}
			num1 = current->data;
			cout << "Q1  " << num1 << endl;

			current = save->linkf;
			for (int i = 0; i != num; ++i) {
				current = current->linkf;
			}
			num1 = current->data;
			cout << "Q2  " << num1 << endl;
		}
	}




	current = head->linkf;
	num = 0;
	num1 = 0;
	set[num] = current->data;
	tally[num] = 1;
	do {
		current = current->linkf;
		if (set[num] != current->data) // 1,1,2,2,3,3,4,4
		{
			num = num + 1;
			set[num] = current->data;
		}
		tally[num] = tally[num] + 1;
	} while (current->linkf != NULL);
	num = 1;
	//num1 = tally[num];
	do {
		if (tally[num2] == tally[num]) {
			mode = false;
		}
		if (tally[num2] < tally[num]) {
			num2 = num;
			mode = true;
		}
		num = num + 1;
	} while (tally[num] != 0);

	if (mode == true)
	{
		cout << "Mode  " << set[num2] << endl;
		cout << "num  " << num << endl;
	}
	else
	{
		cout << "Mode does not exist" << endl;
	}



	// FInd range
	num1 = tail->data - head->linkf->data;
	cout << "Range  " << num1 << endl;
}

//Ross function's
void Addition1(){

	float num1, num2, result;
	//set numbers to 0
	num1 = num2 = 0;
	//inputs numbers
	cout << "Please enter a Number: ";
	cin >> num1;
	cout << "Please enter a second Number: ";
	cin >> num2;

	//calls addition function
	result = Addition(num1, num2);
	//use this function if you want the numbers to be input after the function is called.
	//result=Addition();


	cout << result << endl;

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
void Multiplication1(){

	float num1, num2, result;
	//set numbers to 0
	num1 = num2 = 0;
	//inputs numbers
	cout << "Please enter a Number: ";
	cin >> num1;
	cout << "Please enter a second Number: ";
	cin >> num2;

	//calls Multiplication function
	result = Multiplication(num1, num2);
	//use this function if you want the numbers to be input after the function is called.
	//result=Multiplication();


	cout << result << endl;

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
void Subtraction1(){
	float num1, num2, result;
	//set numbers to 0
	num1 = num2 = 0;
	//inputs numbers
	cout << "Please enter a Number: ";
	cin >> num1;
	cout << "Please enter a second Number: ";
	cin >> num2;

	//calls Subtraction function
	result = Subtraction(num1, num2);
	//use this function if you want the numbers to be input after the function is called.
	//result=Subtraction();


	cout << result << endl;

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

void Divison1(){
float result;
result=0;

//calls Multiplication function
result=Division();


cout << result<<endl;
}

float Division(){
	float num1,num2,Quoitent;
	//initialize all numbers
	num1=num2=Quoitent=0;
	cout << "Please enter a Number: ";
	cin >> num1;
	cout << "Please enter a second Number: ";
	cin >> num2;
        Quoitent=num1/num2;
	return Quoitent;
}

//Joshua's Functions
void squareroot1(){

	cout << squareroot() << endl;
}

double squareroot(){

		double root;
		double r;
		cout << "Enter a number to find squareroot of ";
		cin >> r;
		root = pow(r, 0.5);
		return root;

}

void squared1(){

	cout << squared() << endl;
}

double squared(){

	double square;
	double s;
	cout << "Enter a number to be squared ";
	cin >> s;
	square = s*s;
	return square;
}

void power1(){

	cout << power() << endl;
}

int power(){

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

void logarithm1(){

	cout << logarithm() << endl;
}


double logarithm()
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

