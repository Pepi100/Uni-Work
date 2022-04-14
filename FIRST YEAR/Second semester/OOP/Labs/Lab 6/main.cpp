#include <iostream>
#include <utility>
#include "IoBase.h"
#include <memory>
#include <vector>

using namespace std;


class Participant:public IoBase{
private:
    string nume;
    string CNP;
    vector<string> limbaje;
public:
    Participant() {nume = "", CNP = "00000000000000"}

    Participant(const string &nume, const string &cnp, const vector<string> &limbaje) : nume(nume), CNP(cnp),
                                                                                        limbaje(limbaje) {}

    istream &read(istream &is) override {
        IoBase::read(is);
        cout<<"Nume: ";
        cin>>nume;
        cout<<"CNP: ";
        cin>>CNP;


        return is;
    }
}



int main() {





    return 0;
}
