#include <iostream>
#include <vector>
#include "util/IoBase.h"
#include <string>

using namespace std;

class Jucarie: public IoBase{
protected:
    string nume;
    string tip;
    int dimensiune;
public:
    Jucarie() = default;

    Jucarie(const string &nume, const string &tip, int dimensiune) : nume(nume), tip(tip), dimensiune(dimensiune) {}

    const string &getNume() const {
        return nume;
    }

    const string &getTip() const {
        return tip;
    }

    int getDimensiune() const {
        return dimensiune;
    }

    void setNume(const string &nume) {
        Jucarie::nume = nume;
    }

    void setTip(const string &tip) {
        Jucarie::tip = tip;
    }

    void setDimensiune(int dimensiune) {
        Jucarie::dimensiune = dimensiune;
    }

    istream &read(istream &is) override {
        IoBase::read(is);
        cout << "Nume: ";
        is >> nume;
        cout << "Tip: ";
        is >> tip;
        cout << "Dimensiune: ";
        is >> dimensiune;
        return is;
    }

    ostream &write(ostream &os) const override {
        IoBase::write(os);
        os << "Nume: "<<nume<<endl;
        os << "Tip: "<<tip<<endl;
        os << "Dimensiune: "<< dimensiune<<endl;
        return os;
    }
};

class Clasica: public Jucarie{
private:
    string material;
    string culoare;
public:

    const string &getMaterial() const {
        return material;
    }

    const string &getCuloare() const {
        return culoare;
    }

    void setMaterial(const string &material) {
        Clasica::material = material;
    }

    void setCuloare(const string &culoare) {
        Clasica::culoare = culoare;
    }

    Clasica() = default;

    Clasica(const string &nume, const string &tip, int dimensiune, const string &material, const string &culoare)
            : Jucarie(nume, tip, dimensiune), material(material), culoare(culoare) {}


    istream &read(istream &is) override {
        Jucarie::read(is);
        cout<< "Material: ";
        is>>material;
        cout<<"Culoare: ";
        is>>culoare;
    }

    ostream &write(ostream &os) const override {
         Jucarie::write(os);
        os << "Material: "<<material<<endl;
        os << "Culoare: "<<culoare<<endl;

         return os;
    }
};


class Educativa: public virtual Jucarie{
protected:
    string abilitate;
public:

    const string &getAbilitate() const {
        return abilitate;
    }

    void setAbilitate(const string &abilitate) {
        Educativa::abilitate = abilitate;
    }

};


class Electronica: public virtual Jucarie{
protected:
    int baterii;
public:

    int getBaterii() const {
        return baterii;
    }

    void setBaterii(int baterii) {
        Electronica::baterii = baterii;
    }

    Electronica() =default;

    Electronica(const string &nume, const string &tip, int dimensiune, int baterii) : Jucarie(nume, tip, dimensiune),
                                                                                      baterii(baterii) {}

    istream &read(istream &is) override {
         Jucarie::read(is);
         cout<<"Numar baterii: ";
         is>>baterii;
         return is;
    }

    ostream &write(ostream &os) const override {
        Jucarie::write(os);
        os << "Numar baterii: "<<baterii<<endl;

        return os;
    }
};


class Moderna: public Educativa, public Electronica{
private:
    string brand;
    string model;
public:


};


int main() {
    Clasica j;

    cin>>j;
    cout<<j;
    return 0;
}
