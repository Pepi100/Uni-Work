#include <iostream>
#include <stdlib.h>

using namespace std;

int n, m;
int vInitial[100];
int rezultat[100];
int aparitii[33];
int ultima[33];


void afisare(){
    for(int i=0;i<3*n;i++)
        cout<<rezultat[i];
    cout<<'\n';
    exit(0);

}

void btk(int k){
    if(k==3*n){
        afisare();
    }else{
        if(vInitial[k] != 0){ //daca are o valoare presetata, verificam ca ea sa fie corecta

                int aux = vInitial[k];


                if( k-ultima[aux] > m && aparitii[aux] < 3){
                    aparitii[aux]++;
                    int retinut = ultima[aux];
                    ultima[aux] = k;
                    rezultat[k] = aux;
                    btk(k+1);
                    aparitii[aux]--;
                    ultima[aux] = retinut;
                }

        }else{ //daca nu, ii dam un for
            for(int aux = 1; aux <= n; aux++){

                if( k-ultima[aux] > m && aparitii[aux] < 3){

                    aparitii[aux]++;

                    int retinut = ultima[aux];
                    ultima[aux] = k;

                    rezultat[k] = aux;
                    btk(k+1);

                    aparitii[aux]--;
                    ultima[aux] = retinut;
                }


            }

        }

    }

}


int main()
{
    cin>>n>>m;
    for(int i=0;i<3*n;i++){
        cin>>vInitial[i];
        ultima[i]=-30;
    }


    btk(0);
    cout<<-1<<'\n';


    return 0;
}
