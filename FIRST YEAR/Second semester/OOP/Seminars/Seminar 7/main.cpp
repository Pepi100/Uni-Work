#include <iostream>
using namespace std;



class B{
    int x;
public:
    B(int i=0){x=i;}
};

class cls{
     int x;
public:
    void setX(int x) {
        cls::x = x;
    }
}a;

int cls::x;
cls b;
int main() {
    cls a;
    cls::f();

    return 0;
}
