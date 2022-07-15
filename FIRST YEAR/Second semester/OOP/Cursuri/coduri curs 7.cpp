#include <iostream>

using namespace std;

class Baza
{
protected:
    int x;
    virtual void citire(){cout<<"B\n"; cin>>x;}
private:
    virtual void afisare(){cout<<"B\n"; cout<<x<<" ";}
public:
///    friend istream& operator>>(istream& in, Baza& b){ in>>b.x; return in;}
    friend istream& operator>>(istream& in, Baza& b) { b.citire(); return in;}
    void afis(){ afisare(); }
};

class Derivata :public Baza
{
    int y;
public:
    void citire(){cout<<"D\n"; Baza::citire(); cin>>y;}
    void afisare(){cout<<"D\n"; cout<<x<<" "<<y<<" ";}
///    friend istream& operator>>(istream& in, Derivata& b){ cout<<"D\n"; in>>b.x>>b.y; return in;}
};

int main()
{
    Baza *b = new Baza();
    cin>>*b;
    b = new Derivata();
    cin>>*b;
    b->afis();
    /*
    Baza b;
    cin>>b;
    Derivata d;
    cin>>d;
    */
    /*
    Baza *p = new Derivata();
    p->citire();
    p->afisare();*/
    return 0;
}
