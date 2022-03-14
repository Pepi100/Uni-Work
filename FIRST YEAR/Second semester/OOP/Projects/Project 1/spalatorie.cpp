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
    bool libera = true;
    Durata timpRamas;
    int capsule;
public:
    MasinaSpalat( bool _libera, Durata& _timpRamas, int _capsule){
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

    Durata getTimpRamas(){
        return timpRamas;
    }


};


class Spalatorie{
private:
    int numarMasini;
    MasinaSpalat masini[5];
public:
    void listeazaMasini(){
        if(numarMasini = 0){
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

};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
