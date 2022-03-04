#include <iostream>
#include <algorithm>

using namespace std;


class Film{
private:
    string titlu;
    int likeuri;

public:
    Film(){
        titlu = "";
        likeuri = 0;
    }
    Film(string _titlu, int _likeuri){
        titlu = _titlu;
        likeuri = _likeuri;
    }

    int getLikeuri(){
        return likeuri;
    }

    string getTitlu(){
        return titlu;
    }

    void citeste(){
        string _titlu;
        int _likeuri;
        getline(cin, _titlu);
        cin>>_likeuri;
        cin.get();
        titlu= _titlu;
        likeuri = _likeuri;

    }

};

bool maiMare(Film f1, Film f2){
    return f1.getLikeuri() > f2.getLikeuri();
}

void afisarePopulare(int n, Film filme[], int k){

    sort(filme, filme + n, maiMare);


    cout<<"Cele mai populare "<<k<<" filme:\n";
    for(int i=0;i<k;i++){
        cout<<filme[i].getTitlu()<<" like-uri: "<<filme[i].getLikeuri()<<"\n";
    }

}


int main() {

    Film filme[5];

    for(int i=0;i<=4;i++){
        filme[i].citeste();
    }

    afisarePopulare(5, filme, 2);

    return 0;
}
