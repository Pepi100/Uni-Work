#include <iostream>
#include <vector>

using namespace std;




//Daca nodul i apare inainte nodului j intr-o parcurgere de tip dfs, atunci putem presupune ca i apare inainte lui j in orice lista de adiacenta
//astfel, daca sortam listele de adiacenta astfel incat i sa fie inainte lui j, ca o parcurgere dfs facuta de noi ar trebui ca i sa fie inaintea lui j
// ulterior pornim noi un dfs din nodul 1 si verificam daca ordineDfsinea este aceeasi

//check dfs



int p[100001], viz[100001], poz[100001];
vector<vector<int>> adiacenta;
vector<int> ordineDfs;


void dfs(int n, int nod) {
    viz[nod] = 1;
    ordineDfs.push_back(nod);


    for (int i=0; i < adiacenta[nod].size();i++) {
        if (viz[adiacenta[nod][i] ] == 0) {
            dfs(n, adiacenta[nod][i]);
        }
    }

}

int main() {
    int n, m;
    ordineDfs.push_back(0);
    vector <int> gol;
    adiacenta.push_back(gol);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        adiacenta.push_back(gol);
        cin >> p[i];
        poz[p[i]] = i;
    }
    int x, y;
    for(int i=1;i<=m;i++){
        cin >> x >> y;
        adiacenta[x].push_back(y);
        adiacenta[y].push_back(x);
    }

    //sortam toate listele de adiacenta astfel incat nodurile sa fie in ordinea data in vectorul p
    for (int i=1; i<=n; i++) {

        for(int j=0;j<adiacenta[i].size();j++){
            for(int k=0;k<adiacenta[i].size()-j-1;k++){
                if(poz[adiacenta[i][k]] > poz[adiacenta[i][k+1]]){
                    swap(adiacenta[i][k],adiacenta[i][k+1]);
                }
            }
        }

    }


    dfs(n, 1);


    for (int i=1; i < ordineDfs.size(); i++) {

        if (p[i] != ordineDfs[i]){
            cout<<0;
            return 0;
        }

    }
    cout<<1;
    return 0;
}