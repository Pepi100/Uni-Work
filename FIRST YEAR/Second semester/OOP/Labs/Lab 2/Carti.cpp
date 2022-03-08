#include <iostream>
#include <algorithm>

using namespace std;

class Carte{
private:
    string titlu;
    int nr_pagini;
    int pag_curenta=0;


public:
    void citeste(){
        int numar;
        cout<< "Titlu: ";
        cin>>titlu;
        cout<< "Numar pagini: ";
        cin>>nr_pagini;
        cout<< "Pagina curenta: ";
        cin>>numar;
        while(numar > nr_pagini){
            cout<<"Nu poti sari la pagina "<<numar<<" din "<<nr_pagini<<", deoarece nu exista!\n";
            cout<< "Citeste din nou pagina curenta: ";
            cin>>numar;
        }
        nr_pagini = numar;

        cin.get();
    }

    void afiseaza(){
        cout<<"Titlu: "<<titlu<<'\n';
        cout<<"Numar pagini: "<<nr_pagini<<'\n';
        cout<<"Pagina curenta: "<<pag_curenta<<'\n';
    }

    void setPaginaCurenta(int numar){
        if(numar > nr_pagini){
            cout<<"Nu poti sari la pagina "<<numar<<" din "<<nr_pagini<<", deoarece nu exista!\n";
        }
        else{
            pag_curenta = numar;
        }

    }
    void setPagini(int new_nr_pagini){
        if(new_nr_pagini < pag_curenta){
            cout<<"Numarul paginii curente nu poate fi mai mare decat numarul total de pagini, modifica acest numar prima data!";
        }else{
            pag_curenta = new_nr_pagini;
        }
    }

    void setTitlu(string new_title){
        titlu = new_title;
    }

    int getPaginaCurenta(){
        return pag_curenta;
    }

    string getTilu(){
        return titlu;
    }

    int getPaginaMaxima(){
        return nr_pagini;
    }

};


int main() {

    Carte c;
    c.citeste();
    c.afiseaza();

    c.setPaginaCurenta(30);
    c.afiseaza();

    c.setPaginaCurenta(c.getPaginaMaxima() + 1);

}
