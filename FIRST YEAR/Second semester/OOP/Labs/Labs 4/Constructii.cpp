#include <iostream>
#include <vector>
using namespace std;

class ConstructionProduct{
private:
    string nume;
    int cantitate;
    string unitate;
    float pret;

public:

    int getCantitate() const {
        return cantitate;
    }

    float getPret() const;

    const string &getNume() const {
        return nume;
    }

    const string &getUnitate() const {
        return unitate;
    }

    ConstructionProduct() {}

    ConstructionProduct(int cantitate, const string &unitate, float pret) : cantitate(cantitate), unitate(unitate),
                                                                            pret(pret) {}
    ConstructionProduct operator++(){
        cantitate+=1;
        return *this;
    }

    ConstructionProduct operator++(int){

        ConstructionProduct p1;
        p1.cantitate = cantitate;
        p1.pret = pret;
        p1.nume = nume;
        p1.unitate =  unitate;
        cantitate+=1;
        return p1;
    };

    ConstructionProduct operator+=(int crestere){
        ConstructionProduct p1;
        p1.cantitate = cantitate;
        p1.pret = pret;
        p1.nume = nume;
        p1.unitate =  unitate;
        cantitate+=crestere;
        return p1;
    }

    friend ostream &operator<<(ostream &os, const ConstructionProduct &produs);
    friend istream &operator>>(istream &is, ConstructionProduct &produs);

};
ostream &operator<<(ostream &os, const ConstructionProduct &produs){
    os<<produs.nume<<" ("<<produs.unitate<<") x "<<produs.cantitate<<"\n"<<produs.cantitate<<" x "<< produs.pret<<" = "<<produs.cantitate * produs.pret<<" RON\n";
    return os;
}

istream &operator>>(istream &is, ConstructionProduct &produs){
    cout<<"Nume: ";
    is >>produs.nume;
    cout<<"\nCantitate: ";
    is >> produs.cantitate;
    cout<<"\nUnitate de masura: ";
    is >> produs.unitate;
    cout<<"\nPret: ";
    is >> produs.pret;

    return is;
}

float ConstructionProduct::getPret() const {
    return pret;
}


void chitanta(vector<ConstructionProduct> produse){
    float total;
    for(int i=0; i<produse.size();i++){
        cout<<i+1<<". "<<produse[i];
        total += produse[i].getPret() * produse[i].getCantitate();
    }

    cout<<"-----\nTotal: "<< total<<"RON\n";
}




int main() {

  int n;
  cout<<"Numar produse: ";
  cin>>n;
  vector<ConstructionProduct> produse;
  ConstructionProduct p;
  for(int i=1; i<=n;i++){
      cin>>p;
      produse.push_back(p);
  }

    chitanta(produse);


}



