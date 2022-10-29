#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

//Algoritmul Tarjan
//pentru fiecare nod nevizitat pornim o parcurgere dfs
//Adaugam la vizitarea unui nod acesta este adaugat pe stiva si primeste un id
//pentru nodul curent vizitam totate nodurile adiacente
//deoarece oferim id-urile in ordine crescatoare, primul nod vizitat dintr-o componenta conexa ca vi nodul cu id-ul cel mai mic
//astfel, cand ajungem cu parcurgerea la un nod cu un id mai mic, stim ca apartin aceleiasi componente conexe

//dupa acest procedeu, daca id-ul curent este egal cu low-ul, nodul curent este un nod de "inceput" pentru componenta conexa a lui
//asftel scoatem de pe stack nodurile pana ajungem la cel curent, iar acestea vor fi parte a componentei conexe curente


int n, m;

int onStack[100001], id[100001], low[100001], idcurent=1,componente=0;
//onStack ne spune daca un nod se afla sau nu pe stack
//id ne spune daca un nod a fost sau nu vizitat, iar daca da, ce Id a primit
stack <int> stiva;
vector <int> adiacenta[100001];

vector <vector <int>> rez;

void dfs(int curent) {
    id[curent] = idcurent;
    low[curent] = idcurent;
    idcurent++;
    stiva.push(curent);
    onStack[curent] = 1;

    for (int i=0;i < adiacenta[curent].size();i++) {
        if (id[ adiacenta[curent][i]] == 0) {
            dfs(adiacenta[curent][i]);
            low[curent] = min(low[curent], low[adiacenta[curent][i]]);
        }
        else if (onStack[adiacenta[curent][i]]) {
            low[curent] = min(low[curent], id[adiacenta[curent][i]]);
        }
    }
    if (id[curent] == low[curent]) {
        vector <int> comp;
        int node;

        node = stiva.top();
        stiva.pop();
        onStack[node] = 0;
        comp.push_back(node);

        while (curent != node) {
            node = stiva.top();
            stiva.pop();
            onStack[node] = 0;
            comp.push_back(node);
        } ;
        rez.push_back(comp);
        componente++;
    }
}


int main() {

    fin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        fin >> u >> v;
        adiacenta[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (id[i] == 0) {
            dfs(i);
        }
    }

    fout << componente <<endl;
    for (int i = 0; i < rez.size(); i++) {
        for (int j = 0; j < rez[i].size(); j++) {
            fout << rez[i][j] << " ";
        }
        fout << endl;
    }
    return 0;
}