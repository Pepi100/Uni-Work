#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

ifstream fin ("graf.in");
ofstream fout ("graf.out");

//Pornim o parcurgere de tip dfs din toate nodurile de control
// Distanta de la un nod de control la un al nod va fi adancimea la care a ajuns dfs-ul
// Pentru un nod care a fost deja parcurs, continuam parcurgerea doar daca am reusit sa ajungem in el cu o distanta mai mica

int matrice[200][200];
vector <int> control;
vector <int> dist(200,INT16_MAX);

void dfs(int n,int nod, int d){

    for(int i=0;i<=n;i++){
        if(matrice[nod][i] ==1 && dist[i] > d+1){
            dist[i] = d+1;
            dfs(n, i, d+1);
        }
    }
}




int main() {
    int n, m,a,b;
    fin>>n>>m;
    for(int i=1;i<=m;i++){
        fin>>a>>b;
        matrice[a][b]=1;
        matrice[b][a]=1;
    }

    while(fin>>a){
        control.push_back(a);
    }

    for(int i=0;i<control.size();i++){
        dist[control[i]] = 0;
        dfs(n,control[i], 0);
    }


    for(int i=1;i<=n;i++){
        if(dist[i] == INT16_MAX) fout<<-1<<" ";
        else fout<<dist[i]<<" ";
    }


    return 0;
}
