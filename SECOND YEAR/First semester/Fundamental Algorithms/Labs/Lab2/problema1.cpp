#include <iostream>
#include <vector>
using namespace std;

//codeforces 919D


//daca are ciclu, afisam -1
// precalcupare: dp
//dp[nod][c] cele mai multe caractere c pe un lant care se termina in nodul asta
//nod -> vec
//for(auto vec:v[nod])
//  for(int c=0;c<26;c++){
/*
 * procesez nodurile care nu au alte noduri care intra in ele
 *
 *
 * sortare topologica
 *
 * daca am muchie (u,v) atunci u <v
 * while(n)
 * for(fiecare nod)
 * daca gradul interior al lui i este 0
 * il pun in coada
 * fac grad[j] -- pentru toate nodurile in care intra i
 *
 *
 */


int n, m;
vector <char> litera(1);
vector<vector<int>> adiacenta(1);



void bfs( int nod){

}


int main() {
    char a;
    int x,y;
    vector<int> b;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a;
        litera.push_back(a);
        adiacenta.push_back(b);
    }

    for(int i=1;i<=m;i++){
        cin>>x>>y;
        adiacenta[x].push_back(y);
    }


    return 0;
}
