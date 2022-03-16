#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class InterestPoint{
private:
    int vizitatori;
    float x, y;
public:
    InterestPoint() {}

    InterestPoint( int vizitatori, float x, float y) : vizitatori(vizitatori), x(x), y(y) {}

    float getDistance(InterestPoint p2){
        float d1 = abs(x - p2.x), d2= abs(y - p2.y);
        return sqrt(d1*d1+d2*d2);
    }


    friend ostream &operator<<(ostream &os, const InterestPoint &punct);
    friend istream &operator>>(istream &is, InterestPoint &punct);
};

ostream &operator<<(ostream &os, const InterestPoint &punct){
    os<<" Viziatori: "<<punct.vizitatori<<" Coordonate: "<< punct.x<<", "<<punct.y<<"\n";
    return os;
}
istream &operator>>(istream &is, InterestPoint &punct){
    //cout<<"Numar vizitatori: ";
    is >> punct.vizitatori;
    //cout<<"Coordonate: ";
    is>>punct.x>>punct.y;
    return is;
}


class BikeTrail{
private:
    string nume;
    string oras;
    vector<InterestPoint> puncte;

public:
    BikeTrail() {}

    BikeTrail(const string &nume, const string &oras, const vector<InterestPoint> &puncte) : nume(nume), oras(oras),
                                                                                             puncte(puncte) {}
    friend ostream &operator<<(ostream &os, const BikeTrail &trail);
    friend istream &operator>>(istream &is, BikeTrail &trail);

     string getNume() const {
        return nume;
    }

    void setNume(const string _nume) {
        nume = _nume;
    }

     string getOras() const {
        return oras;
    }

    void setOras(const string _oras) {
        oras = _oras;
    }

    vector<InterestPoint> getPuncte(){
         return puncte;
     }


};
ostream &operator<<(ostream &os, const BikeTrail &trail){
    os<<"Nume: "<< trail.nume<<" Oras: "<<trail.oras<<"\n";
    os<<"Puncte interes: \n";
    for(int i=0; i< trail.puncte.size(); i++){
        os<<trail.puncte[i]<<" ";
    }

    return os;
}


istream &operator>>(istream &is, BikeTrail &trail){
    is>> trail.nume>>trail.oras;
    int nr;
    is>>nr;
    InterestPoint ip;
    for(int i=1; i<=nr; i++){
        cin>>ip;
        trail.puncte.push_back(ip);
    }


    return is;

}

void rezolvare(BikeTrail trail){
    int a, b, c;
    vector<InterestPoint> v = trail.getPuncte();
    int maxim = 0;
    for(int i = 0; i<trail.getPuncte().size();i++){
        for(int j = 0; j<trail.getPuncte().size();j++){
            for(int k = 0; k<trail.getPuncte().size();k++){
                if( i!=j && j!=k && i!=k && v[i].getDistance(v[j])+v[j].getDistance(v[k]) > maxim ){
                    a=i,b=j,c=k;
                    maxim = v[i].getDistance(v[j])+v[j].getDistance(v[k]);
                }
            }
        }

    }

    cout<<"Distanta maxima dintre 3 puncte: "<<maxim<<"\n Punctele:\n";
    cout<<v[a]<<v[b]<<v[c];

}



int main() {
    BikeTrail b;
    cin>>b;
    rezolvare(b);

}


/*
Traseu#1
Constanta
5
102  0 0
404  10 10
3    1 1
22   3 2
1001 5 0
*/

