
#ifndef TEMACTI_ARRAY_H
#define TEMACTI_ARRAY_H

#include <iosfwd>

class Array{
protected:
    int n;
    int *v = nullptr;
public:

    //constructori cu si fara parametri
    Array() {
        n=1;
        v= new int[1];

    }

    Array(int n, int *v){
        this->n = n;
        int *temp =  new int[n+1];
        for(int i=0;i<n;i++){
            temp[i]=v[i];
        }
        delete[] v;

        v= temp;

    }

    //constructor de copiere

    Array(const Array &a){
        n = a.n;
        int *temp =  new int[n+1];
        for(int i=0;i<n;i++){
            temp[i]=a.v[i];
        }
        delete[] v;

        v= temp;
    }


    //destructor
    virtual ~Array() {
        delete []v;
    }

    //getteri

    int getN() const;

    int *getV() const;

    //avem un singur setter deoarece nu are sens ca il setam pe N fara a-l seta pe v sau invers
    virtual void setNV(int n,int _v[]);



    //metodele pentru suma, maxim si minim sunt constante deoarece acestea nu modifica array-ul
    long long getSum()const;

    virtual int getMax() const;

    virtual int getMin() const;

    int getPozMax() const;

    int getPozMin() const;


    //am facut posibila si sortarea descrescatoare prin parametrul optional order
    //daca order este un numar negativ, atuci sortarea se va realiza descrescator
    void sort(int order);

    //Operatori:


    bool operator==( Array a) const ;

    bool operator!=( Array a)const;
    Array operator = (Array a);

    int operator[] (int i);


    virtual void afisare();
    virtual void citire();

    // Definim operatorii >> si << ca functii friend pentru ca acestia sa aiba acces la datele private ale clasei array
    friend std::ostream& operator << (std::ostream& os, Array a);
    friend std::istream& operator >> (std::istream& is, Array &a);
};



#endif //TEMACTI_ARRAY_H
