#pragma once

class Load
{
    private:
        double consumption;
    public:
        Load(double consumption);
        ~Load();
        double getConsumption() const;
};

