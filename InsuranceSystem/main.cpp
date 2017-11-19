#include <iostream>
#include <Act.h>
using namespace std;

int main()
{

String name;
   String vehicle_make;
   String gender;
   int age;
   int driving_regularity;
   double car_value;
   double excess;
   int claims_history;

    for(;;){
     cout << "*****Welcome to the motor vehicle insurance system*****" << endl;
     cout <<"Please enter your name" endl;
     cin>>name;
     cout <<"Please enter yor gender (M or F)" endl;
     cin>>gender
     cout <<"Please enter your age" endl;
     cin>>age;
      cout <<"Please enter how many days on average you drive in a week (1-7)" endl;
     cin>>driving_regularity;
     cout<< "Please enter how many insurance claims youve made in the past";
     cin<<claims_history;
      cout <<"Please enter the current market value in Ksh of your vehicle" endl;
     cin>>car_value;
      cout <<"Please enter the excess in Ksh youre willing to pay" endl;
     cin>>excess;






    }

    return 0;
}
