#include <bits/stdc++.h>
#include "ArrayMinMax.h"
#include "Array.h"

using namespace std;



 void Array::setNV(int n,int _v[]) {
    this->n = n;
    v= new int[n];
    for(int i=0;i<n;i++){
        v[i]=_v[i];
    }
}

long long Array::getSum()const{
    //iteram prin toate elementele vectorului si calculam suma
    long long sum=0;
    for(int i=0; i<n;i++) sum += v[i];

    return sum;

}

int Array::getMax() const {
    int maxim = INT32_MIN;
    for(int i=0; i<n;i++) maxim = max(maxim, v[i]);

    return maxim;
}

int Array::getMin() const {
    int minim = INT32_MAX;
    for(int i=0; i<n;i++) minim = min(minim, v[i]);

    return minim;
}

int Array::getPozMin() const {
    int minim = INT32_MAX, poz=0;

    //daca minimul se regaseste de mai multe ori, o vom returna pe prima dintre acestea

    for(int i=0; i<n;i++)
        if(minim > v[i]){
            minim = v[i];
            poz = i;
        }

    return poz;
}

int Array::getPozMax() const {
    int maxim = INT32_MIN, poz=0;

    //daca maximul se regaseste de mai multe ori, o vom returna pe prima dintre acestea

    for(int i=0; i<n;i++)
        if(maxim < v[i]){
            maxim = v[i];
            poz = i;
        }

    return poz;
}

void Array::sort(int order=1){
    if(order >= 0 ) order =1;
    else order =-1;

    //bubble sort

    for(int i=1;i<n;i++){
        for(int j=0; j<n-i;j++){
            if(order * v[j] > order *v[j+1]){ //daca order este -1, sortarea se va realiza descrescator
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }

}


bool Array::operator==( Array a) const {
    if(n != a.n) return false;

    for(int i=0;i<n;i++){
        if(v[i] != a.v[i]) return false;
    }

    return true;
}


bool Array::operator!=( Array a)const {
if(n != a.n) return true;

for(int i=0;i<n;i++){
if(v[i] != a.v[i]) return true;
}

return false;
}


Array Array::operator = (Array a){
    n = a.n;
    int *temp = new int[n+1];
    for(int i=0;i<n;i++){
        temp[i] = a.v[i];
    }
    delete []v;
    v=temp;

    return *this;
}

int Array::operator[] (int i){
    if(i<=n)
        return v[i];
    else return v[0]; // daca indicele dat nu exista in vector, returam valoare primului element
}

void Array::citire() {
    cout<<"Introduceti numarul de elemente: ";
    cin>>n;
    cout<<"Introduceti "<<n<<" elemente: ";
    int *temp =  new int[n+1];
    for(int i=0;i<n;i++){
        cin>>temp[i];
    }
    delete[] v;

    v= temp;

}

void Array::afisare() {
    cout<<"Vectorul are "<< n<<" elemente:\n";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";

}



ostream& operator << (ostream& os, Array a){
    os<<"Vectorul are "<< a.n<<" elemente:\n";
    for(int i=0;i<a.n;i++){
        os<<a.v[i]<<" ";
    }
    os<<"\n";

    return os;
}


istream& operator >> (istream& is, Array &a){
    cout<<"Introduceti numarul de elemente: ";
    is>>a.n;
    cout<<"Introduceti "<<a.n<<" elemente: ";
    int *temp =  new int[a.n+1];
    for(int i=0;i<a.n;i++){
        cin>>temp[i];
    }
    delete[] a.v;

    a.v= temp;

    return is;
}

int Array::getN() const {
    return n;
}

int *Array::getV() const {
    return v;
}


void ArrayMinMax::afisare() {
    cout<<"Vectorul are "<< n<<" elemente:\n";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    cout<<"Valoarea minima este: "<<minValue<<" Valoarea maxima este: "<<maxValue<<"\nAceastea sunt calculate in timp constant.\n";


}

void ArrayMinMax::citire() {
    cout<<"Introduceti numarul de elemente: ";
    cin>>n;
    cout<<"Introduceti "<<n<<" elemente: ";
    int *temp =  new int[n+1];
    for(int i=0;i<n;i++){
        cin>>temp[i];
        if(i==0){
            minValue = temp[i];
            maxValue = temp[i];
        }

        if(minValue > temp[i]){
            setMinValue(temp[i]);
        }
        if(maxValue < temp[i]){
            setMaxValue(temp[i]);
        }

    }
    delete[] v;

    v= temp;

}


ArrayMinMax::ArrayMinMax(int n, int *v){
    minValue = v[1];
    maxValue = v[1];
    this->n = n;
    int *temp =  new int[n+1];
    for(int i=0;i<n;i++){
        temp[i]=v[i];
        if(minValue > v[i]){
            setMinValue(v[i]);
        }
        if(maxValue < v[i]){
            setMaxValue(v[i]);
        }

    }
    delete[] v;

    v= temp;

}

void ArrayMinMax::setMinValue(int minValue) {
    ArrayMinMax::minValue = minValue;
}

void ArrayMinMax::setMaxValue(int maxValue) {
    ArrayMinMax::maxValue = maxValue;
}


int ArrayMinMax::getMax() const {
    return maxValue;
}

int ArrayMinMax::getMin() const {

    return minValue;
}

int ArrayMinMax::getMinValue() const {
    return minValue;
}

int ArrayMinMax::getMaxValue() const {
    return maxValue;
}

ArrayMinMax::ArrayMinMax() = default;

void meniu(){

    Array* v[20];


    int arrayuri=0, input;


    cout<<"Aveti "<< arrayuri<<" array-uri. Alegeti o optiune:\n"<<"1. Adaugati un array.\n"<<"2. Stergeti un array.\n"<<"3. Vizualizati un array.\n"<<"0. Iesire.\n";
    cin>>input;

    while(input != 0){
        if(input == 1) {

            cout<<"Ce tip de array doriti sa introduceti?:\n1. Array simplu.\n2. Array Min Max.\n";
            int arrType;
            cin>>arrType;
            if(arrType == 1) {



                arrayuri++;

                v[arrayuri] = new Array();
                v[arrayuri] ->citire();

            }else{
                arrayuri++;

                v[arrayuri] = new ArrayMinMax();
                v[arrayuri] ->citire();
            }
        }
        if(input == 2){
            int x;
            cout<<"Introduceti numarul array-ului pe care doriti sa il stergeti (1 - "<<arrayuri<<"):";
            cin>>x;

            while(x > arrayuri){
                cout<<"Acest array nu exista, va rugam reintroduceti: ";
                cin>>x;
            }

            //eliminam array-ul din vector mutand la stanga toate elementele cu indicele > x

            for(int i=x; i < arrayuri; i++){
                v[i] = v[i+1];
            }
            arrayuri--;

        }
        if(input == 3){
            int arr;
            cout<<"Introduceti numarul array-ului pe care doriti sa il vizualizati (1 -> "<<arrayuri<<"):";
            cin>>arr;

            while(arr > arrayuri || arr < 1){
                cout<<"Acest array nu exista, va rugam reintroduceti: ";
                cin>>arr;
            }


            v[arr]->afisare();
            int x;
            cout<<" Alegeti o optiune:\n"<<"1. Calculati minimul.\n"<<"2. Calculati maxium.\n"<<"3. Calculati pozitia minimului.\n"<<"4. Calculati pozitia maximului.\n"<<"5. Calculati suma elementelor.\n"<<"6. Reintroduceti elementele.\n"<<"7. Sortati elementele.\n"<<"0. Inapoi.\n";
            cin>>x;

            while(x != 0){
                while(x > 7 || x < 0){
                    cout<<"Acesta optiune nu exista, va rugam reintroduceti: ";
                    cin>>x;
                }

                switch (x) {
                    case 1:
                        cout<<"Valoarea minima din array este: "<<v[arr]->getMin() <<".\n";
                        break;
                    case 2:
                        cout<<"Valoarea maxima din array este: "<<v[arr]->getMax() <<".\n";
                        break;
                    case 3:
                        cout<<"Pozitia valorii minime din array este: "<<v[arr]->getPozMin() <<".\n";
                        break;
                    case 4:
                        cout<<"Pozitia valorii maxime din array este: "<<v[arr]->getPozMax() <<".\n";
                        break;
                    case 5:
                        cout<<"Suma elementelor din array este: "<<v[arr]->getSum() <<".\n";
                        break;
                    case 6:

                        v[arr] ->citire();
                        break;
                    case 7:
                        cout<<"Crescator / Descrescator? ( 1 / 0 ): ";
                        int order;
                        cin>>order;
                        if(order == 1){
                            v[arr]->sort();
                        }else{
                            v[arr]->sort(-1);
                        }
                        cout<<"Vectorul a fost sortat!\n";
                        break;
                    default:
                        break;
                }
                v[arr]->afisare();
                cout<<" Alegeti o optiune:\n"<<"1. Calculati minimul.\n"<<"2. Calculati maxium.\n"<<"3. Calculati pozitia minimului.\n"<<"4. Calculati pozitia maximului.\n"<<"5. Calculati suma elementelor.\n"<<"6. Reintroduceti elementele.\n"<<"7. Sortati elementele.\n"<<"0. Inapoi.\n";
                cin>>x;

            }



        }

        cout<<"Aveti "<< arrayuri<<" array-uri. Alegeti o optiune:\n"<<"1. Adaugati un array.\n"<<"2. Stergeti un array.\n"<<"3. Vizualizati un array.\n"<<"0. Iesire.\n";
        cin>>input;
    }

}

int main(){

    meniu();
}