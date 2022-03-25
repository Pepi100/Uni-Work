#include <iostream>
using namespace std;


class Baza{

    int x;
protected:
    int y;
public:
    void afis(){
        cout<<"B\n";
    }
};

class Derivata : public Baza{


public:
    void afis(){
        cout<<"C\n";
    }
    void f(){
        cout<<x<<" ";
        cout<<y<<endl;
    }
};

class Derivata2 : private Derivata{
public:
    void g(){
        cout<<x<<" ";
        cout<<y<<" ";
    }
};


void f(Baza  b){
    b.afis();
}
int main() {

    Derivata ob;
    f(ob);


    return 0;
}
