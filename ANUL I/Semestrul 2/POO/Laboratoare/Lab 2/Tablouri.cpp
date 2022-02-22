#include <iostream>
#include <algorithm>

using namespace std;

class Tablou {
private:
    string mesaj;
    int pret;
    int inaltime;
    int latime;

public:
    Tablou(){
        mesaj = "";
        pret = 0;
        inaltime = 0;
        latime = 0;
    }

    Tablou(string _mesaj, int _pret, int _inaltime, int _latime){
        mesaj = _mesaj;
        pret = _pret;
        inaltime = _inaltime;
        latime = _latime;
    }

   void afisare(){
        cout<<"Mesaj: "<< mesaj <<" Pret: "<< pret<< " Inaltime: "<<inaltime<<" Latime: "<< latime;
    }

    void citeste() {
        cout << "Mesaj motivational: ";
        getline(cin, mesaj);
        cout << "Pret: ";
        cin>>pret;
        cout << "Inaltime: ";
        cin>>inaltime;
        cout << "Latime: ";
        cin>>latime;
        cin.get();
    }
    string getMesaj(){
        return mesaj;
    }
    int nrCuvinte(){
        int cuvinte = 1;

        for(int i=0; i<mesaj.length();i++){
            if(mesaj[i]==' ')
                cuvinte++;
        }

        return cuvinte;
    }

};




int main() {

    int n;
    cin>>n;
    cin.get();
    Tablou tablouri[100];
    for(int i=0;i<n;i++){
        tablouri[i].citeste();
    }

    Tablou maxim;

    for(int i=0;i<n;i++){
        if(tablouri[i].nrCuvinte()>maxim.nrCuvinte()){
            maxim = tablouri[i];
        }
    }

    maxim.afisare();
    cout<< "Numarul maxim de cuvinte este: "<<maxim.nrCuvinte();
}
