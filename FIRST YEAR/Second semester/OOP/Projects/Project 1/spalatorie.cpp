#include <iostream>

using namespace std;

class Durata{
private:
    int minute = 0;
    int secunde = 0;
public:
    Durata(){
        minute = 0;
        secunde = 0;
    }

    Durata(int _minute, int _secunde){
        if(_minute >= 0) minute = _minute;
        else minute = 0;

        if(_secunde >= 0) secunde = _secunde;
        else secunde = 0;

        if(secunde >= 60){
            minute += secunde/60;
            secunde = secunde %60;
        }
    }
    int getMinute(){
        return minute;
    }
    int getSecunde(){
        return secunde;
    }

    int toSeconds(){
        return minute*60 + secunde;
    }


};

class MasinaSpalat{
private:
    bool libera ;
    Durata timpRamas;
    int capsule;
public:
    MasinaSpalat( ){
        libera = true;
        timpRamas = Durata(0,0);
        capsule = 0;
    }

    MasinaSpalat( bool _libera, Durata _timpRamas, int _capsule){
        libera = _libera;
        timpRamas = _timpRamas;
        capsule = _capsule;
    }

    bool isLibera() {
        return libera;
    }

    int getCapsule(){
        return capsule;
    }

    void setTimpRamas( Durata _durata){
        timpRamas = _durata;
    }

    Durata getTimpRamas(){
        return timpRamas;
    }
    void addCapsule(int capsule_extra){
        if(capsule_extra >= 0)
            capsule+= capsule_extra;
    }
    void consumaCapsula(){
        capsule--;
    }


};


class Spalatorie{
private:
    int numarMasini;
    MasinaSpalat *masini;
public:
    Spalatorie(int _numarMasini, MasinaSpalat _masini[]){
        numarMasini = _numarMasini;
        masini = _masini;
    }

    void listeazaMasini(){
        if(numarMasini == 0){
            cout<<"Deocamdata nu sunt masini in aceasta spalatorie.\n";
        }
        else{
                for(int i=0; i<numarMasini;i++){
                    if(masini[i].getCapsule() == 0){
                        cout<<"Masina "<<i+1<<" este neutilizabila, nu mai are capsule.\n";
                    }else{
                        if(masini[i].isLibera() ==  true){
                            cout<<"Masina "<<i+1<<" este libera. Aceasta mai are "<<masini[i].getCapsule()<<" capsule.\n";
                        }else{
                            cout<<"Masina "<<i+1<<" este ocupata pentru inca "<<masini[i].getTimpRamas().getMinute()<<":"<<masini[i].getTimpRamas().getSecunde()<<".\n";
                        }
                    }
                }
            }

    }

    int getNumarMasini(){
        return numarMasini;
    }
    MasinaSpalat* getMasini(){
        return masini;
    }

    void adaugaJob(int masina, Durata durata){
        if(masini[masina].getCapsule() == 0){
            cout<<"Masina "<<masina<<" nu mai are capsule! Adaugati capsule sau incercati alta capsule.\n";
        }else{

            if(masini[masina].isLibera() == false)cout<<"Aceasta masina nu este libera!\n";
            else{
                masini[masina].consumaCapsula();
                masini[masina].setTimpRamas(durata);
            }


        }
    }

};

void listeazaMasiniLibere( Spalatorie spalatorie){
    int nrLibere = 0;
    int libere[5];
    for(int i=0; i< spalatorie.getNumarMasini();i++){
        if(spalatorie.getMasini()->isLibera() == true){
            libere[nrLibere] = i;
            nrLibere++;
        }
    }
    if(nrLibere == 0) cout<< "Nu sunt masini libere la aceasta spalatorie\n";
    else{
        cout<<"Urmatoarele masini sunt libere:";
        for(int i=0; i<nrLibere;i++) cout<<" "<< libere[i];
        cout<<".\n";
    }

}


int main() {
    MasinaSpalat masini[5] = {
            MasinaSpalat(true, Durata(0, 0), 3),
            MasinaSpalat(true, Durata(0, 0), 2),
            MasinaSpalat(true, Durata(0, 0), 5),
    };
    Spalatorie spalatorie(
            3,
            masini
    );

    spalatorie.listeazaMasini();
    listeazaMasiniLibere(spalatorie);


    return 0;
}
