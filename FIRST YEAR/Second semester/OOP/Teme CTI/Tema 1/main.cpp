#include <bits/stdc++.h>
#include <iostream>


using namespace std;



class Array{
private:
    int n;
    int *v = nullptr;
public:

    //constructori cu si fara parametri
    Array() {
        n=1;
        v= new int[1];

    }

    Array(int n, int *v){
        this->n = n;
        int *temp =  new int[n+1];
        for(int i=0;i<n;i++){
            temp[i]=v[i];
        }
        delete[] v;

        v= temp;

    }

    //constructor de copiere

    Array(const Array &a){
        n = a.n;
        int *temp =  new int[n+1];
        for(int i=0;i<n;i++){
            temp[i]=a.v[i];
        }
        delete[] v;

        v= temp;
    }


    //destructor
    virtual ~Array() {
        delete []v;
    }

    //getteri

    int getN() const {
        return n;
    }

    int *getV() const {
        return v;
    }

    //avem un singur setter deoarece nu are sens ca il setam pe N fara a-l seta pe v sau invers
    void setNV(int n,int _v[]) {


        this->n = n;
        v= new int[n];
        for(int i=0;i<n;i++){
            v[i]=_v[i];
        }
    }



    //metodele pentru suma, maxim si minim sunt constante deoarece acestea nu modifica array-ul
    long long getSum()const{
        //iteram prin toate elementele vectorului si calculam suma
        long long sum=0;
        for(int i=0; i<n;i++) sum += v[i];

        return sum;

    }

    int getMax() const {
        int maxim = INT32_MIN;
        for(int i=0; i<n;i++) maxim = max(maxim, v[i]);

        return maxim;
    }

    int getMin() const {
        int minim = INT32_MAX;
        for(int i=0; i<n;i++) minim = min(minim, v[i]);

        return minim;
    }

    int getPozMax() const {
        int maxim = INT32_MIN, poz=0;

        //daca maximul se regaseste de mai multe ori, o vom returna pe prima dintre acestea

        for(int i=0; i<n;i++)
            if(maxim < v[i]){
                maxim = v[i];
                poz = i;
            }

        return poz;
    }

    int getPozMin() const {
        int minim = INT32_MAX, poz=0;

        //daca minimul se regaseste de mai multe ori, o vom returna pe prima dintre acestea

        for(int i=0; i<n;i++)
            if(minim > v[i]){
                minim = v[i];
                poz = i;
            }

        return poz;
    }


    //am facut posibila si sortarea descrescatoare prin parametrul optional order
    //daca order este un numar negativ, atuci sortarea se va realiza descrescator
    void sort(int order=1){
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

    //Operatori:


    bool operator==( Array a) const {
        if(n != a.n) return false;

        for(int i=0;i<n;i++){
            if(v[i] != a.v[i]) return false;
        }

        return true;
    }

    bool operator!=( Array a) const {
        if(n != a.n) return true;

        for(int i=0;i<n;i++){
            if(v[i] != a.v[i]) return true;
        }

        return false;
    }

    Array operator = (Array a){
        n = a.n;
        int *temp = new int[n+1];
        for(int i=0;i<n;i++){
            temp[i] = a.v[i];
        }
        delete []v;
        v=temp;

        return *this;
    }

    int operator[] (int i){
        if(i<=n)
        return v[i];
        else return v[0]; // daca indicele dat nu exista in vector, returam valoare primului element
    }




    // Definim operatorii >> si << ca functii friend pentru ca acestia sa aiba acces la datele private ale clasei array
    friend ostream& operator << (ostream& os, Array a);
    friend istream& operator >> (istream& is, Array &a);
};

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


void meniu(){

    Array v[20];


    int arrayuri=0, input;


    cout<<"Aveti "<< arrayuri<<" array-uri. Alegeti o optiune:\n"<<"1. Adaugati un array.\n"<<"2. Stergeti un array.\n"<<"3. Vizualizati un array.\n"<<"0. Iesire.\n";
    cin>>input;

    while(input != 0){
        if(input == 1) {

            Array a;
            arrayuri++;
            cin >> a;
            v[arrayuri] = a;
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

            cout<< v[arr];
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
                        cout<<"Valoarea minima din array este: "<<v[arr].getMin() <<".\n";
                        break;
                    case 2:
                        cout<<"Valoarea maxima din array este: "<<v[arr].getMax() <<".\n";
                        break;
                    case 3:
                        cout<<"Pozitia valorii minime din array este: "<<v[arr].getPozMin() <<".\n";
                        break;
                    case 4:
                        cout<<"Pozitia valorii maxime din array este: "<<v[arr].getPozMax() <<".\n";
                        break;
                    case 5:
                        cout<<"Suma elementelor din array este: "<<v[arr].getSum() <<".\n";
                        break;
                    case 6:
                        cin>>v[arr];
                        break;
                    case 7:
                        cout<<"Crescator / Descrescator? ( 1 / 0 ): ";
                        int order;
                        cin>>order;
                        if(order == 1){
                            v[arr].sort();
                        }else{
                            v[arr].sort(-1);
                        }
                        cout<<"Vectorul a fost sortat!\n";
                        break;
                    default:
                        break;
                }
                cout<< v[arr];
                cout<<" Alegeti o optiune:\n"<<"1. Calculati minimul.\n"<<"2. Calculati maxium.\n"<<"3. Calculati pozitia minimului.\n"<<"4. Calculati pozitia maximului.\n"<<"5. Calculati suma elementelor.\n"<<"6. Reintroduceti elementele.\n"<<"7. Sortati elementele.\n"<<"0. Inapoi.\n";
                cin>>x;

            }



        }

        cout<<"Aveti "<< arrayuri<<" array-uri. Alegeti o optiune:\n"<<"1. Adaugati un array.\n"<<"2. Stergeti un array.\n"<<"3. Vizualizati un array.\n"<<"0. Iesire.\n";
        cin>>input;
    }

}

int main(){

    //Meniu

    meniu();

//    Array a;
//    cin>>a;
//    cout<<a[2];

    return 0;
}