#include <fstream>
#include <iostream>
#include <vector>

using namespace std;


ifstream fin("graf.in");


int parents[100002];

int getParent(int n){
    int copie = n;

    while(parents[n] != 0){
        n = parents[n];
    }
    int root = n;
    //parcurgem inca o data pentru a optimiza

    n= copie;
    while(parents[n] != 0){
        copie = parents[n];
        parents[n] = root;
        n=copie;
    }

    return root;
}


int main() {

    int n, m,x,y,k;
    vector<pair<int, int>> muchiiExtra;

    fin>>n>>m;
    int comp_conexe=n;
    for(int i =1; i<=m;i++){
        fin>>x>>y;


//     cout<<getParent(x)<< " "<< getParent(y)<<endl;
            if(getParent(x)!= getParent(y)){
                 parents[getParent(x)] = getParent(y);
                 comp_conexe--;
            }
            else{
                muchiiExtra.push_back({x,y});
            }


    }
    fin>>k;



    //cout<<comp_conexe<<" "<<k<<" "<<muchiiExtra.size();


    //trebuie s avem minim (comp_conexe - k) muchii extra pentru a obtine acele k componente conexe
    //deoarece trebuie sa facem (comp_conexe - k) uniri ce componente conexe

    if(comp_conexe - k > (muchiiExtra.size())){
        cout<<"nu se poate";
    }else{

        cout<<"minim "<< comp_conexe - k<<" mutari cut-paste\n";
        int i=n;
        int m=0;
        int a = -1,b= -1;


        while(comp_conexe > k){
            //trec prin tot vectorul de parinti;
            //elementele care au 0 sunt parinti ai arborilor construiti, ii legam pe acestia

            if(parents[i] == 0 && a==-1){
                a=i;
            }else{
                if(parents[i] == 0 && b==-1){
                    b=i;
                }
            }

            if(a!= -1 && b != -1){
                cout<< "("<<muchiiExtra[m].first<<","<<muchiiExtra[m].second<<") => ("<<a<<","<<b<<")\n";
                b=a;
                a=-1;
                m++;
                comp_conexe--;
            }
            i--;
        }


        //o solutie alternativa ar fi sa facem comp - k cautari in vectorul de parinti, la fiecare cautare identificand 2 tati pe care sa ii unim
        // complexitatea pentru aceasta alternativa este n*k

    }


    return 0;
}
