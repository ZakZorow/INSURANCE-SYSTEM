#ifndef ACT_H
#define ACT_H



class Act
{
    public:

        Act();
        ~Act();
        double calculatePremiumAct();
        void displayDetailsAct();
        bool saveToFileAct();



    protected:


       // string name;
       // string vehicle_make;
       // string gender;
        int age;
        int driving_regularity;
        double car_value;
        double excess;
        int claims_history;
        int policy_number;


    private:
         const double default_premium =12000.00;
};

#endif // ACT_H
