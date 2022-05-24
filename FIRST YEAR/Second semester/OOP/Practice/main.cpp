//Nedelcu Radu-Ioan
//Grupa 152
//Compilator: MinGW w64 9.0
//Tutore: Stefan-Eduard Deaconu


#include <iostream>
#include <vector>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T> v){
    os<<"Vectorul contine elementele: ";
    for(int i=0; i<v.size();i++){
        os<< v[i]<<", ";
    }
    return os;
}


struct Data{
    int an, zi, luna;
};

class Malware{
protected:
    Data date;
    string nume;
    string metoda;
    vector <string> registri;
public:

    Malware();

    Malware(int an, int luna, int zi, const string &nume, const string &metoda, const vector<string> &registri);

    void setDate(const Data &date);

    void setNume(const string &nume);

    void setMetoda(const string &metoda);

    void setRegistri(const vector<string> &registri);

    const Data &getDate() const;

    const string &getNume() const;

    const string &getMetoda() const;

    const vector<string> &getRegistri() const;

    virtual istream& readMalware(istream& is)= 0;

    virtual ostream& printMalware(ostream& os)=0;

    friend istream& operator>>(istream& is, Malware &ob);
    friend ostream& operator<<(ostream& os, Malware &ob);

    virtual ~Malware();
};
istream& operator>>(istream& is, Malware &ob){
    return ob.readMalware(is);
}

ostream& operator<<(ostream& os, Malware &ob){
    return ob.printMalware(os);


}

Malware::~Malware() {

}


const Data &Malware::getDate() const {
    return date;
}

const string &Malware::getNume() const {
    return nume;
}

const string &Malware::getMetoda() const {
    return metoda;
}

const vector<string> &Malware::getRegistri() const {
    return registri;
}

void Malware::setDate(const Data &date) {
    Malware::date = date;
}

void Malware::setNume(const string &nume) {
    Malware::nume = nume;
}

void Malware::setMetoda(const string &metoda) {
    Malware::metoda = metoda;
}

void Malware::setRegistri(const vector<string> &registri) {
    Malware::registri = registri;
}

Malware::Malware(int an, int luna, int zi, const string &nume, const string &metoda, const vector<string> &registri) :nume(nume), metoda(metoda), registri(registri) {
    Malware::date.an = an;
    Malware::date.luna = luna;
    Malware::date.zi = zi;
}

Malware::Malware() = default;


class Rootkit: public virtual Malware{
protected:
    vector <string> importuri;
    vector<string> keywords;
public:
    Rootkit() = default;

    Rootkit(int an, int luna, int zi, const string &nume, const string &metoda, const vector<string> &registri,
            const vector<string> &importuri, const vector<string> &keywords);

    const vector<string> &getImporturi() const;

    void setImporturi(const vector<string> &importuri);

    const vector<string> &getKeywords() const;

    void setKeywords(const vector<string> &keywords);

    virtual istream &readMalware(istream& is) {
        cout<<"Nume:\n";
        getline(is, nume);

        cout<<"Metoda infectare:\n";
        getline(is, metoda);
        cout<<"Data infectarii:\nAn:\n";
        is>>date.an;
        cout<<"Luna:\n";
        is>>date.luna;
        cout<<"Zi:\n";
        is>>date.zi;
        cout<<"Numar registri afectati:\n";
        int n;
        is>>n;
        vector<string> s;
        string reg;
        cout<<"Cititi cei "<<n<<" registri afectati: \n";
        for(int i=1;i<=n;i++){
            is>>reg;
            is.get();
            s.push_back(reg);
        }
        registri = s;
        s.clear();

        cout<<"Numar importuri: \n";
        is>>n;
        cout<<"Cititi cele "<<n<<" importuri: \n";
        for(int i=1;i<=n;i++){
            is>>reg;
            is.get();
            s.push_back(reg);
        }
        importuri = s;
        s.clear();
        cout<<"Numar keywords: \n";
        is>>n;
        cout<<"Cititi cele "<<n<<" keywords: \n";
        for(int i=1;i<=n;i++){
            is>>reg;
            is.get();
            s.push_back(reg);
        }

        keywords = s;

        return is;

    }

    virtual ostream &printMalware(ostream &os){
        cout<<"Data: "<<date.zi<<"."<<date.luna<<"."<<date.an<<endl;
        cout<<"Nume: "<<nume<<endl;
        cout<<"Metoda: "<<metoda<<endl;
        cout<<"Registri: "<<registri<<endl;
        cout<<"Importuri: "<<importuri<<endl;
        cout<<"Stringuri speciale: "<<keywords<<endl;


        return os;
    }

};

const vector<string> &Rootkit::getImporturi() const {
    return importuri;
}

void Rootkit::setImporturi(const vector<string> &importuri) {
    Rootkit::importuri = importuri;
}

const vector<string> &Rootkit::getKeywords() const {
    return keywords;
}

void Rootkit::setKeywords(const vector<string> &keywords) {
    Rootkit::keywords = keywords;
}

Rootkit::Rootkit(int an, int luna, int zi, const string &nume, const string &metoda, const vector<string> &registri,
                 const vector<string> &importuri, const vector<string> &keywords) : Malware(an, luna, zi, nume, metoda,
                                                                                            registri),
                                                                                    importuri(importuri),
                                                                                    keywords(keywords) {}

class Keylogger: public virtual Malware{
protected:
    vector <string> functii;
    vector <string> taste;
public:

    Keylogger(int an, int luna, int zi, const string &nume, const string &metoda, const vector<string> &registri,
              const vector<string> &functii, const vector<string> &taste);

    Keylogger() = default;

    const vector<string> &getFunctii() const;

    void setFunctii(const vector<string> &functii);

    const vector<string> &getTaste() const;

    void setTaste(const vector<string> &taste);

    virtual istream &readMalware(istream& is) {
        cout<<"Nume:\n";
        getline(is, nume);

        cout<<"Metoda infectare:\n";
        getline(is, metoda);
        cout<<"Data infectarii:\nAn:\n";
        is>>date.an;
        cout<<"Luna:\n";
        is>>date.luna;
        cout<<"Zi:\n";
        is>>date.zi;
        cout<<"Numar registri afectati:\n";
        int n;
        is>>n;
        vector<string> s;
        string reg;
        cout<<"Cititi cei "<<n<<" registri afectati: \n";
        for(int i=1;i<=n;i++){
            is>>reg;
            is.get();
            s.push_back(reg);
        }
        registri = s;
        s.clear();

        cout<<"Numar functii: \n";
        is>>n;
        cout<<"Cititi cele "<<n<<" functii: \n";
        for(int i=1;i<=n;i++){
            is>>reg;
            is.get();
            s.push_back(reg);
        }
        functii = s;
        s.clear();
        cout<<"Numar taste: \n";
        is>>n;
        cout<<"Cititi cele "<<n<<" taste: \n";
        for(int i=1;i<=n;i++){
            is>>reg;
            is.get();
            s.push_back(reg);
        }

        taste = s;

        return is;

    }

    virtual ostream &printMalware(ostream &os){
        cout<<"Data: "<<date.zi<<"."<<date.luna<<"."<<date.an<<endl;
        cout<<"Nume: "<<nume<<endl;
        cout<<"Metoda: "<<metoda<<endl;
        cout<<"Registri: "<<registri<<endl;
        cout<<"Functii: "<<functii<<endl;
        cout<<"Taste: "<<taste<<endl;


        return os;
    }


};

const vector<string> &Keylogger::getFunctii() const {
    return functii;
}

void Keylogger::setFunctii(const vector<string> &functii) {
    Keylogger::functii = functii;
}

const vector<string> &Keylogger::getTaste() const {
    return taste;
}

void Keylogger::setTaste(const vector<string> &taste) {
    Keylogger::taste = taste;
}

Keylogger::Keylogger(int an, int luna, int zi, const string &nume, const string &metoda, const vector<string> &registri,
                     const vector<string> &functii, const vector<string> &taste) : Malware(an, luna, zi, nume, metoda,
                                                                                           registri), functii(functii),
                                                                                   taste(taste) {}

class KernelKeylogger: public Rootkit, public Keylogger{
private:
    bool ascundeFisiere;
    bool ascundeRegistri;
public:



    KernelKeylogger(){
        ascundeFisiere = false;
        ascundeRegistri = false;
    }

    bool isAscundeFisiere() const;

    void setAscundeFisiere(bool ascundeFisiere);

    bool isAscundeRegistri() const;

    void setAscundeRegistri(bool ascundeRegistri);


    virtual istream &readMalware(istream& is) {
        cout<<"Nume:\n";
        getline(is, nume);

        cout<<"Metoda infectare:\n";
        getline(is, metoda);
        cout<<"Data infectarii:\nAn:\n";
        is>>date.an;
        cout<<"Luna:\n";
        is>>date.luna;
        cout<<"Zi:\n";
        is>>date.zi;
        cout<<"Numar registri afectati:\n";
        int n;
        is>>n;
        vector<string> s;
        string reg;
        cout<<"Cititi cei "<<n<<" registri afectati: \n";
        for(int i=1;i<=n;i++){
            is>>reg;
            is.get();
            s.push_back(reg);
        }
        registri = s;
        s.clear();

        cout<<"Numar importuri: \n";
        is>>n;
        cout<<"Cititi cele "<<n<<" importuri: \n";
        for(int i=1;i<=n;i++){
            is>>reg;
            is.get();
            s.push_back(reg);
        }
        importuri = s;
        s.clear();
        cout<<"Numar keywords: \n";
        is>>n;
        cout<<"Cititi cele "<<n<<" keywords: \n";
        for(int i=1;i<=n;i++){
            is>>reg;
            is.get();
            s.push_back(reg);
        }

        keywords = s;

        cout<<"Numar functii: \n";
        is>>n;
        cout<<"Cititi cele "<<n<<" functii: \n";
        for(int i=1;i<=n;i++){
            is>>reg;

            s.push_back(reg);
        }
        functii = s;
        s.clear();
        cout<<"Numar taste: \n";
        is>>n;
        cout<<"Cititi cele "<<n<<" taste: \n";
        for(int i=1;i<=n;i++){
            is>>reg;

            s.push_back(reg);
        }

        taste = s;

        return is;

    }

    virtual ostream &printMalware(ostream &os){
        os<<"Data: "<<date.zi<<"."<<date.luna<<"."<<date.an<<endl;
        os<<"Nume: "<<nume<<endl;
        os<<"Metoda: "<<metoda<<endl;
        os<<"Registri: "<<registri<<endl;
        os<<"Importuri: "<<importuri<<endl;
        os<<"Stringuri speciale: "<<keywords<<endl;
        os<<"Functii: "<<functii<<endl;
        os<<"Taste: "<<taste<<endl;


        return os;
    }
};

bool KernelKeylogger::isAscundeFisiere() const {
    return ascundeFisiere;
}

void KernelKeylogger::setAscundeFisiere(bool ascundeFisiere) {
    KernelKeylogger::ascundeFisiere = ascundeFisiere;
}

bool KernelKeylogger::isAscundeRegistri() const {
    return ascundeRegistri;
}

void KernelKeylogger::setAscundeRegistri(bool ascundeRegistri) {
    KernelKeylogger::ascundeRegistri = ascundeRegistri;
}


class Computer{
private:
    static int next_id ;
    int id;
    double rating_final;
    vector <Malware*> virusi;
public:
    Computer(){
        id = next_id;
        next_id++;
        rating_final = 0;
    }

    Computer(int id, double ratingFinal, const vector<Malware *> &virusi);

    int getId() const;

    void setId(int id);

    double getRatingFinal() const;

    void setRatingFinal(double ratingFinal);

    const vector<Malware *> &getVirusi() const;

    void setVirusi(const vector<Malware *> &virusi);

    friend ostream& operator<<(ostream& os, Computer& ob);
    friend istream& operator>>(istream& is, Computer& ob);

};
ostream& operator<<(ostream& os, Computer& ob){
    os<<"Id: "<<ob.id<<endl;
    os<<"Rating final: "<<ob.rating_final<<endl;
    os<<"Virusi: "<<endl;
    for(int i=0; i<ob.virusi.size();i++){
        ob.virusi[i]->printMalware(os);
    }
    return os;
}

istream& operator>>(istream& is, Computer& ob){
//    ob.id = Computer::next_id;
//    Computer::next_id++;
    cout<<"Introduceti numarul de virusi: ";
    int n;
    is>>n;
    vector<Malware*> m;
    Malware* p;
    for(int i=1; i<=n; i++){
        cout<<"Alegeti un tip de malware:\n1.Rootkit\n2.Keylogger\n3.KernelKeylogger\nIntroduceti un numar intre 1 si 3: ";
        int tip;
        is>>tip;
        is.get();
        switch(tip){
            case 1:
                p=new Rootkit;
                break;
            case 2:
                p=new Keylogger;
                break;
            case 3:
                p=new KernelKeylogger;
                break;
            default:
                cout<<"Tipul introdus nu este corect";
                i--;
        }
        is>>*p;
        ob.virusi.push_back(p);
    }

    return is;
}

int Computer::next_id = 0;





int Computer::getId() const {
    return id;
}

void Computer::setId(int id) {
    Computer::id = id;
}

double Computer::getRatingFinal() const {
    return rating_final;
}

void Computer::setRatingFinal(double ratingFinal) {
    rating_final = ratingFinal;
}

const vector<Malware *> &Computer::getVirusi() const {
    return virusi;
}

void Computer::setVirusi(const vector<Malware *> &virusi) {
    Computer::virusi = virusi;
}

Computer::Computer(int id, double ratingFinal, const vector<Malware *> &virusi) : id(id), rating_final(ratingFinal),
                                                                                  virusi(virusi) {}


class menu{
private:
    vector<Computer>;

    static menu* instanta;
public:
};

int main() {

    Computer r;
    cin>>r;
    cout<<r;


    return 0;
}
