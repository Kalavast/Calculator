#include<iostream>
using namespace std; 

/*
Author:
This is for our project and my mission is doing menu function.
should only funciton on main to make it easy.....
note: it may change something on commend.....  
*/
void Menu(); 
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

void Menu(){

int number; 
do{
cout<<"If you want  <1>"<<endl
    <<"if you want  <2>"<<endl
    <<"if you want  <3>"<<endl
    <<" Exit? Enter number 0 "<<endl; 
// please ignore output, i will fix it when i get the functions from you.
cin>>number; 
switch(number)
{
case 1:

// function call right here
break;

case 2:
// function call right here
break;

case 3: 
// function call  right here
break;
} // This is testing area only before applied the final one....
//Also, function works very well and just need to add call functions from other group member.
.
// please note: i may add more caes if there is more call functions..... :)

}while(number != 0); // assume user select zero, loop will stop and exit. 

}
