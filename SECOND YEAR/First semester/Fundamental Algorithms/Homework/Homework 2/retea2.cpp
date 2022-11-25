#include <fstream>
#include <iostream>
#include <iomanip>
#include <math.h>


using namespace std;


ifstream fin("retea2.in");
ofstream fout("retea2.out");


class Coord{
private:
    int x, y;
public:
    int getX() const {
        return x;
    }

    void setX(int x) {
        Coord::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        Coord::y = y;
    }

    double distance(Coord b)const{
        return sqrt(1ll*(x - b.getX())*(x - b.getX()) + 1ll*(y - b.getY())*(y - b.getY()));
    }
};


int main(){

    Coord v[4001];
    double minim[4001];
    int n, m, viz[4001];
    fin >> n >> m;



    int x,y;

    for(int i=1; i<=n; i++){
        fin >> x >> y;
        v[i].setX(x);
        v[i].setY(y);
        viz[i] = 1;
    }


    for(int i=1; i<=m; i++){
        fin >> x >> y;
        v[n+i].setX(x);
        v[n+i].setY(y);

        viz[n+i] = 0;
        minim[n+i] = 9999999999;

        for(int j=1; j<=n; j++) {

            if (minim[n+i] > v[n+i].distance(v[j])) {
                minim[n+i] = v[n+i].distance(v[j]);
            }
        }
    }
//    cout<< dist(v[3],v[1])<<" "<<v[3].distance(v[1]);
    int nod=0, mind;
    double sum = 0;
    for(int k=1;k<=m;k++){
         mind = 9999999999;
        for(int i=1; i<=m; i++)
            if(!viz[n+i] && mind > minim[n+i]) {
                mind = minim[n+i];
                nod = n+i;
            }
        sum += mind;
        viz[nod] = 1;
        for(int i=n; i<=n; i++)
            if(!viz[n+i] && minim[n+i] > v[nod].distance(v[n+i])) {
                minim[n+i] = v[nod].distance(v[n+i]);
            }
    }

    fout<<fixed<<setprecision(6)<<sum;

}