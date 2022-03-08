#include <iostream>
#include "vector"
#include <algorithm>

using namespace std;


class Client{
private:
    int fonduri;
    int id;

public:
    Client(int _fonduri, int _id){
        fonduri = _fonduri;
        id = _id;
    }


    void setFonduri( int _fonduri){
        fonduri = _fonduri;
    }


    int getFonduri(){
        return fonduri;
    }

    int getId(){
        return id;
    }


};

class Banca{
private:
    vector<Client> clienti;
    int nr_clienti = 0;
public:
    void adaugareClient(){
        adaugareClient(0);
    }

    void adaugareClient(int _suma){
        int last_id ;
        if (nr_clienti == 0 ){
            last_id = 0;
        }else{
            last_id = clienti[clienti.size()-1].getId();
        };
        Client c(_suma, last_id+1);
        clienti.push_back(c);
        nr_clienti++;
    }

    int sumaTotala(){
        int _suma = 0;
        for(int i=0;i<nr_clienti;i++){
            if(clienti[i].getFonduri() >= 0) _suma += clienti[i].getFonduri();
            //am considerat ca anumiti clienti pot avea o balanta negativa (datorii la banca) dar in acest caz, suma de bani din banca nu este afectata
        }
        return _suma;
    }

    int clientiPeste( int suma){
        int _numarClienti = 0;
        for(int i=0;i<nr_clienti;i++){
            if( clienti[i].getFonduri() >= suma) _numarClienti++;
        }

        return _numarClienti;
    }

    int clientiSub( int suma){
        int _numarClienti = 0;
        for(int i=0;i<nr_clienti;i++){
            if( clienti[i].getFonduri() < suma) _numarClienti++;
        }

        return _numarClienti;
    }

    void procentClientiPeste(int suma){
        int _numarClienti = clientiPeste(suma);
        int procent = (_numarClienti * 1.0 / nr_clienti)*100;

        cout<< "Sunt "<<procent<<"% clienti din cei "<<nr_clienti<<" cu fonduri peste "<<suma<<".\n";
    }


};



int main() {
    int s;
    Banca b;
    for(int i=1;i<=5;i++){
     cin>>s;
     b.adaugareClient(s);
    }

    b.procentClientiPeste(1000);
    cout<<b.clientiPeste(100);

}


//Cerinta B:

//Pentru a rezolva problema fara a folosi clasa client va trebui sa memoram ca atribute ale clasei banca atat id-urile cat si sumele fiecarui client
//Astfel, am avea nevoie de 2 vectori, sau de un singur vector daca dorim sa folosim indicele din vector pe post de id.
//Metodele clasei banca pot functiona similar, daor da vor prelua datele din cei 2 fectori mai sus mentionati.
