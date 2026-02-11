#pragma once
#include <string>

class Module
{
    private:
        std::string name;
        bool isTurnedOn;
        double production;
    public:
        Module(double production);
        ~Module();
        bool getIsTurnedOn() const;
        double getProduction() const;
        void setIsTurnedOn(bool b);
        void printInfo();
};