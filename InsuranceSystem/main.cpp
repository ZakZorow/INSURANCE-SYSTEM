#include <iostream>
#include<fstream>
#include<string>
using namespace std;


class Act
{
     protected:

        string name;
        string vehicle_make;
        string gender;
        int age;
        int driving_regularity;
        int car_value;
        int excess;
        double premium;
        int claims_history;
        int policy_number;

    public:
      const double default_premium =12000.00;

        Act(string name_c, string vehicle_make_c, string gender_c, int age_c,
            int driving_regularity_c, double car_value_c, double excess_c
            , int claims_history_c){

                name = name_c;
                vehicle_make = vehicle_make_c;
                gender = gender_c;
                age = age_c;
                driving_regularity = driving_regularity_c;
                car_value = car_value_c;
                excess = excess_c;
                claims_history = claims_history_c;

        }
        ~Act(){

        }

        double calculatePremiumAct(){

          premium = default_premium;


          return premium;
        }


       void displayDetails(){
             cout<<endl;
             cout<<"--------------------------------------------------"<<endl;
             cout << " Name : " <<name <<endl;
             cout << " Vehicle Make : "<< vehicle_make<<endl;
             cout << " Gender : "<< gender << endl;
             cout << " Age : "<< age << endl;
             cout << " Driving Regularity : "<< driving_regularity<<endl;
             cout << " Car Value " << car_value << " Ksh "<<endl;
             cout << " Excess "<< excess << " Ksh "<<endl;
             cout << " Claims History " << claims_history << endl;
             cout<<"--------------------------------------------------"<<endl;
             cout <<" Premium : "<< premium   << "Ksh pa"<<endl;
             cout<<endl;
             cout<<endl;

        }

        void saveToFile(){
        ofstream policy_file("policies.txt", ios::out | ios::app);

        if(policy_file.is_open()){
             policy_file<<endl;
             policy_file<<"--------------------------------------------------"<<endl;
             policy_file<< " Name : " <<name <<endl;
             policy_file<< " Vehicle Make : "<< vehicle_make<<endl;
             policy_file<< " Gender : "<< gender << endl;
             policy_file<< " Age : "<< age << endl;
             policy_file<< " Driving Regularity : "<< driving_regularity<<endl;
             policy_file<< " Car Value : " << car_value << " Ksh "<<endl;
             policy_file<< " Excess : "<< excess << " Ksh "<<endl;
             policy_file<< " Claims History : " << claims_history << endl;
             policy_file<<"--------------------------------------------------"<<endl;
             policy_file<<" Premium : "<< premium   << "Ksh pa"<<endl;
             policy_file<<endl;
             policy_file.close();

             cout<<endl;
             cout<<" saved customer to file "<<endl;

        }else{

         cout<<endl;
         cout<<" could not save to file "<<endl;

        }


        }

       static void showFileDetails(){

            string line;

            ifstream policy_file;

            policy_file.open("policies.txt", ios::in);

            if(!policy_file){

                    cout<<"There are no stored policy records" <<endl;
                    cout<<endl;

            }else{

            while(getline(policy_file, line )){

              cout<<line <<endl;

            }


           policy_file.close();

            }


        }




};

class ThirdParty: public Act{


 public:
      ThirdParty(string name_c, string vehicle_make_c, string gender_c, int age_c,
                 int driving_regularity_c, double car_value_c, double excess_c
                ,int claims_history_c): Act(name_c, vehicle_make_c,  gender_c,  age_c,
                 driving_regularity_c,car_value_c, excess_c
                 ,claims_history_c){

                name = name_c;
                vehicle_make = vehicle_make_c;
                gender = gender_c;
                age = age_c;
                driving_regularity = driving_regularity_c;
                car_value = car_value_c;
                excess = excess_c;
                claims_history = claims_history_c;

        }


        double calculatePremiumThirdParty(){

            double points = 0;

            if(claims_history == 0){

                points+=1;

            }else if(claims_history >= 1 && claims_history <= 3){

                points+=3;

                   }else if(claims_history >3 && claims_history <= 5){


                       points+=5;
                          }else if(claims_history >5){

                              points+=5;


            }

            if(excess >=100000 && excess <= 300000){

                points+=6;
            }else if(excess >=300000 && excess <= 700000){

                points+=4;

            }else if(excess >=700000){

            points+=2;
            }


             if(driving_regularity ==1){

                 points+=1;

             } else if (driving_regularity == 2){

                  points+=2;

             } else if (driving_regularity == 3){

                  points+=3;

             } else if (driving_regularity == 4){

                  points+=4;

             } else if (driving_regularity == 5){

                  points+=5;


             } else if (driving_regularity == 6){

                  points+=6;

             } else if (driving_regularity == 7){

                  points+=7;


             }


             if(gender.compare("M") == 0 ){

                points+=7;


             }else if(gender.compare("F") == 0){

                 points+=4;


             }

               if(vehicle_make.compare("Mercedes") == 0 ){

                points+=7;


             }else if(vehicle_make.compare("toyota") == 0){

                 points+=3;

                    }else if(vehicle_make.compare("bmw") == 0){

                 points+=7;

                    }else if(vehicle_make.compare("audi") == 0){

                 points+=6;

                    }else if(vehicle_make.compare("nissan") == 0){

                 points+=5;

                    }else if(vehicle_make.compare("honda") == 0){

                 points+=4;


             }

            if(age >=18 && age <=25){

            points+=8;

            }else if(age >25 && age <= 40){

            points+=5;

            }else if(age >40){


            points+=6;
            }

            premium = calculatePremiumAct() +(((points/6)/1000) * car_value);





            return premium;

        }





};

class ThirdPartyFireTheft: public ThirdParty{


 public:
      ThirdPartyFireTheft(string name_c, string vehicle_make_c, string gender_c, int age_c,
                 int driving_regularity_c, double car_value_c, double excess_c
                ,int claims_history_c): ThirdParty(name_c, vehicle_make_c,  gender_c,  age_c,
                 driving_regularity_c,car_value_c, excess_c
                 ,claims_history_c){

                name = name_c;
                vehicle_make = vehicle_make_c;
                gender = gender_c;
                age = age_c;
                driving_regularity = driving_regularity_c;
                car_value = car_value_c;
                excess = excess_c;
                claims_history = claims_history_c;

        }





};

class Comprehensive: public ThirdPartyFireTheft{


 public:
      Comprehensive(string name_c, string vehicle_make_c, string gender_c, int age_c,
                 int driving_regularity_c, double car_value_c, double excess_c
                ,int claims_history_c): ThirdPartyFireTheft(name_c, vehicle_make_c,  gender_c,  age_c,
                 driving_regularity_c,car_value_c, excess_c
                 ,claims_history_c){

                name = name_c;
                vehicle_make = vehicle_make_c;
                gender = gender_c;
                age = age_c;
                driving_regularity = driving_regularity_c;
                car_value = car_value_c;
                excess = excess_c;
                claims_history = claims_history_c;

        }





};




int main()
{
   int policy;
   string name;
   string vehicle_make;
   string gender;
   int age;
   int driving_regularity;
   double car_value;
   double excess;
   int claims_history;
   int option;

    for(;;){
     cout << "  *****Welcome to the motor vehicle insurance system*****  " << endl;
     cout <<endl;
     cout<<endl;
     cout<<"  Enter 1 to add new customer  "<<endl;
     cout<<"  Enter 2 to view existing customers  "<<endl;
     cout<<"  Enter 3 to exit the sytem  "<<endl;
     cin>>option;

     if(option == 1){



     cout<<endl;
     cout <<" Please enter your name (no spaces)" <<endl;
     cin>>name;
     cout <<" Please enter yor gender (M or F)" <<endl;
     cin>>gender;
     cout <<" Please enter your age" <<endl;
     cin>>age;
     cout <<" Please enter your vehicle make"<< endl;
     cin>>vehicle_make;
     cout <<" Please enter how many days on average you drive in a week (1-7)"<< endl;
     cin>>driving_regularity;
     cout<< " Please enter how many insurance claims youve made in the past"<<endl;
     cin>>claims_history;
     cout <<" Please enter the current market value in Ksh of your vehicle"<< endl;
     cin>>car_value;
     cout <<" Please enter the excess in Ksh youre willing to pay ( minimum 100000 Ksh)"<< endl;
     cin>>excess;

    cout << " please select the insurance policy you wish to use "<< endl;
    cout<<"  1. Act only policy"<<endl;
    cout<<"  2. Third party policy" <<endl;
    cout<<"  3. Third party fire & Theft policy"<<endl;
    cout <<"  4. comprehensive policy"<<endl;
    cin >>policy;

    switch(policy){

case 1:

    {


     Act act(name, vehicle_make, gender, age, driving_regularity, car_value,excess,claims_history);
     act.calculatePremiumAct();
     act.saveToFile();
    }
    break;

case 2:
    {



    ThirdParty tp(name, vehicle_make, gender, age, driving_regularity, car_value,excess,claims_history);
     tp.calculatePremiumThirdParty();
     tp.saveToFile();
    }
    break;

case 3:
{



}
    break;

case 4:

    break;

default:

    cout<< "incorrect policy selected"<<endl;






    }

  //    Act act(name, vehicle_make, gender, age, driving_regularity, car_value,excess,claims_history);

     //tp.displayDetails();

     }else if(option == 2){

     Act::showFileDetails();

     }else if(option == 3) {

      break;


     }else{

     break;
     }




    }

    return 0;
}
