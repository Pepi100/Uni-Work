#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Este necesar sa verificam daca graful dat este bipartit
// Folosind o parcurgere de tip BFS, impartim nodurile in 2 grupuri astfel:
// pentru fiecare nod din grupul 1, nodurile adiacente lui vor fi puse in grupul 2 si invers
// daca gasim un nod adiacent celui curent, care a fost deja pus in grupul celui curent atunci graful nu este bipartit



class Solution {
public:



    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        queue<int> coada;
//        vector<int> vizitat(n+1,0);
        vector<int> grup(n+1,0);

        for(int i=1;i<=n;i++){

            if(grup[i] == 0){
//                cout<<"|";
                grup[i] =1;
                coada.push(i);

                while(!coada.empty()){

                    int curent = coada.front();
                    coada.pop();
//                    cout<<curent;
                    //parcugrem lista de dislike-uri si adaugam la coada + adaugam in grupuri
                    for(int j=0;j<dislikes.size();j++){

                        if(dislikes[j][0] == curent ){
                            if(grup[dislikes[j][1]] == 0){
                                coada.push(dislikes[j][1]);
                                grup[dislikes[j][1]] = (grup[curent]==1)?2:1; //daca grupul curent e 1, atunci il punem in 2, daca e 2 il punem in 1
                            }else{
                                if(grup[dislikes[j][1]] == grup[curent])
                                    return false;
                            }

                        }

                        if(dislikes[j][1] == curent ){
                            if(grup[dislikes[j][0]] == 0){
                                coada.push(dislikes[j][0]);
                                grup[dislikes[j][0]] = (grup[curent]==1)?2:1; //daca grupul curent e 1, atunci il punem in 2, daca e 2 il punem in 1
                            }else{
                                if(grup[dislikes[j][0]] == grup[curent])
                                    return false;
                            }

                        }

                    }

                }

            }
        }

        return true;

    }

    vector<vector<int>> possibleBipartition2(int n, vector<vector<int>>& dislikes) {
        queue<int> coada;
//        vector<int> vizitat(n+1,0);
        vector<int> grup(n+1,0);

        for(int i=1;i<=n;i++){

            if(grup[i] == 0){
//                cout<<"|";
                grup[i] =1;
                coada.push(i);

                while(!coada.empty()){

                    int curent = coada.front();
                    coada.pop();
//                    cout<<curent;
                    //parcugrem lista de dislike-uri si adaugam la coada + adaugam in grupuri
                    for(int j=0;j<dislikes.size();j++){

                        if(dislikes[j][0] == curent ){
                            if(grup[dislikes[j][1]] == 0){
                                coada.push(dislikes[j][1]);
                                grup[dislikes[j][1]] = (grup[curent]==1)?2:1; //daca grupul curent e 1, atunci il punem in 2, daca e 2 il punem in 1
                            }else{
                                if(grup[dislikes[j][1]] == grup[curent])
                                    return {{},{}};
                            }

                        }

                        if(dislikes[j][1] == curent ){
                            if(grup[dislikes[j][0]] == 0){
                                coada.push(dislikes[j][0]);
                                grup[dislikes[j][0]] = (grup[curent]==1)?2:1; //daca grupul curent e 1, atunci il punem in 2, daca e 2 il punem in 1
                            }else{
                                if(grup[dislikes[j][0]] == grup[curent])
                                    return {{},{}};
                            }

                        }

                    }

                }

            }
        }

        //construim cei doi vectori pe baza vectorului grup;
        vector<vector<int>> rez={{},{}};
        for(int i=1;i<=n;i++){
            rez[grup[i]-1].push_back(i);
        }

        return rez;

    }


};

int main() {
    int n, m;
    vector<vector<int>> d;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a, b;
        cin>>a>>b;
        d.push_back({a,b});
    }

    Solution s;
    vector<vector<int>> rez = s.possibleBipartition2(n,d);

    cout<<"Grupul 1: ";
    for(auto i:rez[0]){
        cout<<i<<" ";
    }
    cout<<"\nGrupul 2: ";
    for(auto i:rez[1]){
        cout<<i<<" ";
    }

    return 0;
}
