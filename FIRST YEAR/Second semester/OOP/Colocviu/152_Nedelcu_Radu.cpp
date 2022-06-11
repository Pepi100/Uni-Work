//Nedelcu Radu-Ioan
//Grupa 152
//Compilator: MinGW w64 9.0
//Tutore: Stefan-Eduard Deaconu
//examen.oop.fmi@gmail.com


//NU ESTE REZOLVAT COMPLET SAU TOTAL CORECT! A nu se lua ca exemlu!

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T> v){
    os<<"Vectorul contine elementele: ";
    for(int i=0; i<v.size();i++){
        os<< v[i]<<", ";
    }
    return os;
}

class Bilet{
protected:
    int taxa;
    bool validat;
public:
    int getTaxa() const;

    void setTaxa(int taxa);

    virtual bool isValid(){
            if(validat) return false;
             return true;
        }

    Bilet() = default;

    Bilet(bool validat);

    bool isValidat() const;

    void setValidat(bool validat);

   virtual istream& readBilet(istream &is){
        return is;
    }

    virtual ostream& printBilet(ostream &os){
       return os;
   }

    friend istream& operator>>(istream& is, Bilet &ob);

    friend ostream& operator<<(ostream& os, Bilet &ob);

};

ostream& operator<<(ostream& os, Bilet &ob){
    return ob.printBilet(os);
}

istream& operator>>(istream& is, Bilet &ob){
    return ob.readBilet(is);
}

bool Bilet::isValidat() const {
    return validat;
}

void Bilet::setValidat(bool validat) {
    Bilet::validat = validat;
}

Bilet::Bilet(bool validat) : validat(validat) {}

int Bilet::getTaxa() const {
    return taxa;
}

void Bilet::setTaxa(int taxa) {
    Bilet::taxa = taxa;
}

class BiletSuprafata:virtual public Bilet{
private:
    static double taxa;
public:

    BiletSuprafata() = default;

    virtual istream& readBilet(istream &is){
        cout<<"Biletul a fost validat? [1/0]";
        is>>validat;
        is.get();
        return is;
    }

    virtual ostream& printBilet(ostream &os){
        os<<"Bilet Suprafata:\n";
        os<<"Validat: "<<validat<<"\n";
        os<<"Pret: "<<taxa<<"\n";


        return os;
    }

};

double BiletSuprafata::taxa = 2;

class BiletMetrou:virtual public Bilet{
private:
    static double taxa;

public:
    BiletMetrou() = default;

    virtual istream& readBilet(istream &is){
        cout<<"Biletul a fost validat? [1/0]";
        is>>validat;
        is.get();
        return is;
    }
    virtual ostream& printBilet(ostream &os){
        os<<"Bilet Suprafata:\n";
        os<<"Validat: "<<validat<<"\n";
        os<<"Pret: "<<taxa<<"\n";


        return os;
    }
};

double BiletMetrou::taxa = 2.5;

class BiletTranzit: public BiletMetrou, public BiletSuprafata{
private:
    static double taxa;
    int timpRamas = 90;
public:
    BiletTranzit() = default;

    bool isValid(){
        if(validat == false) return true;
        else{
            if(timpRamas > 0){
                return true;
            }
        }
        timpRamas = 90;
        return false;
    }

    virtual istream& readBilet(istream &is){
        cout<<"Biletul a fost validat? [1/0]";
        is>>validat;
        is.get();
        if(validat == true){
            cout<<"Timpul ramas pana la expirate: [ 0 = expirat]";
            is>>timpRamas;
        }
        return is;
    }

    virtual ostream& printBilet(ostream &os){
        os<<"Bilet Suprafata:\n";
        os<<"Validat: "<<validat<<"\n";
        if(validat){
            if(timpRamas == 0){
                os<<"Biletul este expirat!\n";
            }else{
                os<<"Biletul este valabil inca "<<timpRamas<<" minute.\n";
            }
        }
        os<<"Pret: "<<taxa<<"\n";

        return os;
    }
};

double BiletTranzit::taxa = 3.0;


class Card{
protected:
    string proprietar;
    Bilet lastBilet ;
    vector <Bilet*> bilete;
    int bileteValidate = 0;

public:
    virtual bool valid(){
        return true;
    }



    const string &getProprietar() const;

    void setProprietar(const string &proprietar);

    const Bilet &getLastBilet() const;

    void setLastBilet(const Bilet &lastBilet);

    const vector<Bilet *> &getBilete() const;

    void setBilete(const vector<Bilet *> &bilete);

    Card() = default;

    virtual void adaugareBilet(Bilet &b){
        bilete.push_back(&b);
    }

    Card(const string &proprietar, const Bilet &lastBilet, const vector<Bilet *> &bilete);

    friend istream& operator>>(istream &is, Card &ob);

    virtual istream& readCard(istream &is){

        cout<<"Cititi numele proprietarului:\n";
        getline(is, proprietar);
        cout<<"Cititi numarul de bilete:\n";
        int n;
        cin>>n;
        int tip;
        is.get();
        Bilet *p;
        for(int i=1;i<=n;i++){
            cout<<"Introduceti tipul biletului:\n 1: Bilet Suprafata\n 2: Bilet Metrou\n 3: Bilet Tranzit\n";
            cin>>tip;
            switch(tip){
                case 1:
                    p=new BiletSuprafata;
                    break;
                case 2:
                    p=new BiletMetrou;
                    break;
                case 3:
                    p=new BiletTranzit;
                    break;
                default:
                    cout<<"Nu ati introdus un tip vvalid de bilet!";
                    i--;

            }
            cin>>*p;
            bilete.push_back(p);


        }



        return is;
    }

    friend ostream& operator<<(ostream &os, Card &ob);

};

ostream& operator<<(ostream &os, Card &ob){
    os<<"Nume proprietar: "<<ob.proprietar<<'\n';
    os<<"Bilete:\n";
    for(int i=0;i<ob.bilete.size();i++){
        ob.bilete[i]->printBilet(os);
    }

    return os;

}

istream& operator>>(istream &is, Card &ob){
    return ob.readCard(is);
}

Card::Card(const string &proprietar, const Bilet &lastBilet, const vector<Bilet *> &bilete) : proprietar(proprietar),
                                                                                              lastBilet(lastBilet),
                                                                                              bilete(bilete) {}

const string &Card::getProprietar() const {
    return proprietar;
}

void Card::setProprietar(const string &proprietar) {
    Card::proprietar = proprietar;
}

const Bilet &Card::getLastBilet() const {
    return lastBilet;
}

void Card::setLastBilet(const Bilet &lastBilet) {
    Card::lastBilet = lastBilet;
}

const vector<Bilet *> &Card::getBilete() const {
    return bilete;
}

void Card::setBilete(const vector<Bilet *> &bilete) {
    Card::bilete = bilete;
}


class CardSuprafata: public Card{
protected:
public:
    virtual istream& readCard(istream &is){

        cout<<"Cititi numele proprietarului:\n";
        getline(is, proprietar);
        cout<<"Cititi numarul de bilete:\n";
        int n;
        cin>>n;
        int tip;
        is.get();
        Bilet *p;
        for(int i=1;i<=n;i++){
            cout<<"Introduceti tipul biletului:\n 1: Bilet Suprafata\n 2: Bilet Metrou\n";
            cin>>tip;
            switch(tip){
                case 1:
                    p=new BiletSuprafata;
                    break;
                case 2:
                    p=new BiletMetrou;
                    break;

                default:
                    cout<<"Nu ati introdus un tip valid de bilet!";
                    i--;

            }
            cin>>*p;
            bilete.push_back(p);


        }



        return is;
    }


};

class CardMetrou: public Card{
protected:
public:

    virtual bool valid(){
        bool ok = false;
        for(auto i: bilete){
            if(i->isValid()){
                i->setValidat(false);
                ok = true;
                break;
            }
        }
        return ok;

    }

    virtual istream& readCard(istream &is) {

        cout << "Cititi numele proprietarului:\n";
        getline(is, proprietar);
        cout << "Cititi numarul de bilete:\n";
        int n;
        cin >> n;
        int tip;
        is.get();
        Bilet *p;
        for (int i = 1; i <= n; i++) {
            cout << "Introduceti tipul biletului:\n 1: Bilet Suprafata\n 2: Bilet Metrou\n";
            cin >> tip;
            switch (tip) {
                case 1:
                    p = new BiletSuprafata;
                    break;
                case 2:
                    p = new BiletMetrou;
                    break;

                default:
                    cout << "Nu ati introdus un tip valid de bilet!";
                    i--;

            }
            cin >> *p;
            bilete.push_back(p);


        }
        return is;
    }
};

class CardTranzit: public Card{
public:
    virtual istream& readCard(istream &is) {

        cout << "Cititi numele proprietarului:\n";
        getline(is, proprietar);
        cout << "Cititi numarul de bilete:\n";
        int n;
        is >> n;
        int tip;
        is.get();
        Bilet *p;
        for (int i = 1; i <= n; i++) {
            p = new BiletTranzit;
            cout << "Introduceti biletul de tranzit:\n";
            is >> *p;
            bilete.push_back(p);


        }
        return is;
    }
};

class Aparat{
private:
    string locatie;
    bool inAutobuz;

public:

    void validare(Card &c){
        if(c.valid()){
            cout<<"Validarea a reusit.\n";
        }else{
            cout<<"Validarea a esuat.\n";
        };
    }

    Aparat() = default;

    Aparat(const string &locatie, bool inAutobuz);

    const string &getLocatie() const;

    void setLocatie(const string &locatie);

    bool isInAutobuz() const;

    void setInAutobuz(bool inAutobuz);

    friend ostream& operator<<(ostream &os, Aparat &a);

    friend istream& operator>>(istream &is, Aparat &a);

};
istream& operator>>(istream &is, Aparat &a){
    cout<<"Locatie:\n";
    is>>a.locatie;
    cout<<"Tip: Subteran (0), Suprafata (1):\n";
    is>>a.inAutobuz;
    return is;
}

ostream& operator<<(ostream &os, Aparat &a){
    os<<"Locatie: "<<a.locatie<<'\n';
    if(a.inAutobuz == true){
        os<<"Aparatul se afla intr-un autobuz.\n";
    }
    else{
        os<<"Aparatul se afla in subteran.\n";
    }

    return os;
}

const string &Aparat::getLocatie() const {
    return locatie;
}

void Aparat::setLocatie(const string &locatie) {
    Aparat::locatie = locatie;
}

bool Aparat::isInAutobuz() const {
    return inAutobuz;
}

void Aparat::setInAutobuz(bool inAutobuz) {
    Aparat::inAutobuz = inAutobuz;
}

Aparat::Aparat(const string &locatie, bool inAutobuz) : locatie(locatie), inAutobuz(inAutobuz) {}


int main() {

    CardTranzit b;
    cin>>b;
    cout<<b;

    Aparat a;
    cin>>a;

    a.validare(b);
    cout<<b;


    return 0;
}
