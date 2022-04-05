#include <iostream>
#include "util/IoBase.h"
#include <vector>

using namespace std;



// Orice meniu va putea:
//  * lista optiunile
//  * alege corect una dintre optiuni
//  * va putea fi rulat la infinit (=interactiv din "meniu interactiv")

class BaseMenu {
private:
    int optionsNumber;
public:
    BaseMenu(int optionsNumber) : optionsNumber(optionsNumber) {}


    virtual void listOptions() {

    }

    virtual int chooseOption(int first, int last) {


        int option;
        while(true){
            cout<<"Alegere:  ";
            cin>>option;
            if(option<=last && option>=first)
                return option;
            cout<<"Aceea nu este o optiune:\n";
        }
    }

    virtual void takeAction(int option){}

    virtual void mainLoop() {
        int option = 0;
        while(option != optionsNumber){
            listOptions();
            option= chooseOption(1, optionsNumber);
            takeAction(option);
        }
    }
};

class SimpleMenu:public BaseMenu{
private:
    int optionsNumber =4 ;
public:
    SimpleMenu() : BaseMenu(4) {optionsNumber = 4;}

    void listOptions() override {
        cout<<"Pentru a rula comanda, alege una dintre optiunile de la 1 la 4:\n";
        cout<<"1. Adauga o noua cladire.\n";
        cout<<"2. Sterge o cladire.\n";
        cout<<"3. Modifica o cladire.\n";
        cout<<"4. Iesire.\n";
    }

    void takeAction(int option) override {
        switch (option) {
            case 1: cout<<"Aici se adauga o cladire.\n";
                    break;
            case 2: cout<<"Aici se sterge o cladire.\n";
                    break;
            case 3: cout<<"Aici se modifica o cladire.\n";
                    break;
            case 4: cout<<"Se paraseste programul.\n";
                    break;
        }
        cout<<"\n";
    }

};

class Building:public IoBase{
    string culoare;
    string proprietar;
public:
    const string &getCuloare() const {
        return culoare;
    }

    const string &getProprietar() const {
        return proprietar;
    }

    void setCuloare(const string &culoare) {
        Building::culoare = culoare;
    }

    void setProprietar(const string &proprietar) {
        Building::proprietar = proprietar;
    }

    Building() {}

    Building(const string &culoare, const string &proprietar) : culoare(culoare), proprietar(proprietar) {}

    istream &read(istream &is) override {
        IoBase::read(is);
        cout<<"\nSpecificati proprietarul: ";
        is>>proprietar;
        cout<<"Specificati culoarea: ";
        is>>culoare;

        return is;
    }

    ostream &write(ostream &os) const override {
        IoBase::write(os);
        os<<"Proprietarul este: "<<proprietar<<'\n';
        os<<"Culoarea este: "<<culoare<<'\n';

        return os;
    }
};



class SecondMenu:public BaseMenu{
private:
    vector<Building> buildings;
public:

    SecondMenu() : BaseMenu(5) {}

    SecondMenu(int optionsNumber, const vector<Building> &buildings) : BaseMenu(5), buildings(buildings) {}

    void listOptions() override {
        cout<<"Pentru a rula comanda, alege una dintre optiunile de la 1 la 5:\n";
        cout<<"1. Adauga o noua cladire.\n";
        cout<<"2. Afiseaza cladirile actuale.\n";
        cout<<"3. Sterge o cladire.\n";
        cout<<"4. Modifica o cladire.\n";
        cout<<"5. Iesire.\n";
    }

    void takeAction(int option) override {
        switch (option) {
            case 1: {cout<<"Noua cladire: \n";
                    Building b;
                    cin>>b;
                    buildings.push_back(b);
                    break;}
            case 2: {cout<<"Cladirile actuale: \n";
                    for(int i=0;i<buildings.size();i++){
                        cout<<"Cladirea "<<i+1<<":\n";
                        cout<<buildings[i];
                    }

                    break;}
            case 4: {
                    cout<<"Alegeti cladirea pe care doriti sa o modificati: ";
                    int c;
                    cin>>c;
                    string s;
                    cout<<"\nNoul nume: ";
                    cin>>s;
                    buildings[c].setProprietar(s);
                    cout<<"\nNoua culoare: ";
                    cin>>s;
                    buildings[c].setCuloare(s);

                    break;
                    }
            case 3: {
                cout << "Alegeti cladirea pe care sa o stergeti: .\n";
                int c;
                cin >> c;

                buildings.erase(buildings.begin() + c - 1);
                cout << "Cladirea a fost stearsa! \n";
                }
                break;
            case 5: cout<<"Se paraseste programul!\n";
                break;
        }
        cout<<"\n";
    }

};


int main() {
    SecondMenu s;
    s.mainLoop();

    return 0;
}
