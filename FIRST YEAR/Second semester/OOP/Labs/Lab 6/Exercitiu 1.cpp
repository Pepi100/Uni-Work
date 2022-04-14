#include <iostream>
#include <utility>
#include "IoBase.h"
#include <memory>
#include <vector>

using namespace std;


class Fruct{
private:
    string nume;
    string soi;
public:
    Fruct() {
        nume = "Fruct fara nume";
        soi = "";
    }

    Fruct(string nume, string soi) : nume(std::move(nume)), soi(std::move(soi)) {}

    const string &getNume() const {
        return nume;
    }

    const string &getSoi() const {
        return soi;
    }

    void setNume(const string &nume) {
        Fruct::nume = nume;
    }

    void setSoi(const string &soi) {
        Fruct::soi = soi;
    }

    friend ostream &operator<<(ostream &os, const Fruct &fruct);

    friend istream &operator >>(istream &is, Fruct &fruct);
};

ostream &operator<<(ostream &os, const Fruct &fruct) {
    os << "nume: " << fruct.nume << " soi: " << fruct.soi;
    return os;
}

istream &operator>>(istream &is, Fruct &fruct) {
    cout<<"Nume: ";
    is>>fruct.nume;
    cout<<"Soi: ";
    is>>fruct.soi;

    return is;
}

class Suc:public IoBase{
private:
    int cantitate;
public:
    Suc() {
        cantitate = 0;
    }

    explicit Suc(int cantitate) : cantitate(cantitate) {}

    int getCantitate() const {
        return cantitate;
    }

    void setCantitate(int cantitate) {
        Suc::cantitate = cantitate;
    }

    istream &read(istream &is) override {
         IoBase::read(is);
         cout<<"Cantitate : ";
         cin>>cantitate;

         return is;
    }

    ostream &write(ostream &os) const override {
        IoBase::write(os);
        cout<<"cantitate: "<<cantitate<<'\n';
        return os;

    }

    virtual int quantity() const{
        return cantitate;
    }


};

class SucSimplu:public Suc{
private:
    Fruct fruct;
public:
    SucSimplu() = default;

    SucSimplu(int cantitate, const Fruct &fruct) : Suc(cantitate), fruct(fruct) {}


    ostream &write(ostream &os) const override {
        Suc::write(os);
        cout<<", fruct: "<<fruct;
        return os;
    }

    istream &read(istream &is) override {
        Suc::read(is);
        cout<<"Fruct: ";
        cin>>fruct;
        return is;
    }
};

class SucMixt:public Suc{
private:
    vector <Fruct> fructe;

public:
    SucMixt() = default;

    SucMixt(int cantitate, const vector<Fruct> &fructe) : Suc(cantitate), fructe(fructe) {}


    istream &read(istream &is) override {
         Suc::read(is);
         int numar;
         cout<<"Numar fructe: ";
         cin>>numar;
         Fruct f;
         for(int i=0;i<numar;i++){
             cout<<"Fruct: ";
             cin>>f;
             fructe.push_back(f);
         }

         return is;


    }

    ostream &write(ostream &os) const override {
         Suc::write(os);
         for(int i=0; i< fructe.size();i++){
             cout<<i+1<<". "<<fructe[i]<<endl;
         }
         return os;
    }

};

class SucGheata: public SucMixt{
private:
    int cantitateGheata;
public:



    SucGheata() {cantitateGheata = 0;}

    SucGheata(int cantitate, const vector<Fruct> &fructe, int cantitateGheata) : SucMixt(cantitate, fructe),
                                                                                 cantitateGheata(cantitateGheata) {}

    int getCantitateGheata() const {
        return cantitateGheata;
    }

    void setCantitateGheata(int cantitateGheata) {
        SucGheata::cantitateGheata = cantitateGheata;
    }

    istream &read(istream &is) override {
         SucMixt::read(is);
         cout<<"Cantitate cheata: ";
         cin>>cantitateGheata;

         return is;
    }

    ostream &write(ostream &os) const override {
         SucMixt::write(os);
         cout<<"Cantitate gheata: "<<cantitateGheata<<'\n';
         return os;
    }

    int quantity()const override{
        return cantitateGheata + Suc::quantity();
    }

};



int main() {

    vector<shared_ptr<Suc> > stock = {
            make_shared<SucSimplu>(
                    SucSimplu(550, Fruct("Apple", "Granny Smith"))
            ),
            make_shared<SucMixt>(
                    SucMixt(
                            560,
                            {
                                    Fruct("Apple", "Granny Smith"),
                                    Fruct("Banana", "Musa balbisiana"),
                            }
                    )
            ),
            make_shared<SucGheata>(
                    SucGheata(
                            560,
                            {
                                    Fruct("Apple", "Granny Smith"),
                                    Fruct("Banana", "Musa balbisiana"),
                            },
                            150
                    )
            ),
    };

    for (auto Suc : stock) {
        cout << Suc->quantity()<<" ";

    }



    return 0;
}
