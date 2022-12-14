

#ifndef TEMACTI_ARRAYMINMAX_H
#define TEMACTI_ARRAYMINMAX_H


#include "Array.h"

class ArrayMinMax: public Array{
private:
    int minValue;
    int maxValue;

private:
    void setMinValue(int minValue);

    void setMaxValue(int maxValue);

public:


    ArrayMinMax(int n, int *v);


    ArrayMinMax();


    int getMinValue() const;

    int getMaxValue() const;


    void citire();

    void afisare();

    int getMax() const;

    int getMin() const;
};


#endif //TEMACTI_ARRAYMINMAX_H
