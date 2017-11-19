#ifndef ACT_H
#define ACT_H


class Act
{
    public:

        Act();
        ~Act();
        double calculatePremiumAct();
        void displayDetailsAct()
        bool saveToFileAct();



    protected:

        const double default_premium;
        String name;
        String vehicle_make;
        String gender;
        int age;
        int driving_regularity;
        double car_value;
        double excess;
        int claims_history;
        int policy_number;


    private:
};

#endif // ACT_H
