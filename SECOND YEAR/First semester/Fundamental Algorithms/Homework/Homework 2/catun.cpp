
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define INF 1000000000


using namespace std;
ifstream fin ("catun.in");
ofstream fout ("catun.out");



int main(){

    int n, m, k;
    fin>>n>>m>>k;
    vector<vector<pair<int, int>>> lista(n+1);
    vector<int> minDistFort(n+1, 0);
    vector<int> minDist(n+1, -1*INF);
    vector<int> visited(n+1);

    int isFort[n+1];
    for(int i=0;i<=n;i++){
        isFort[i]=0;
    }
    int f;
    for(int i=0; i<k; i++)
    {
        fin>>f;
        isFort[f]=1;
    }

    int x, y, z;
    for(int i=0; i<m; i++){
        fin>>x>>y>>z;
        lista[x].push_back({y, -z});
        lista[y].push_back({x, -z});
    }




    priority_queue<pair<int, int>> q;

    for(int i=1;i<=n;i++)
    {
        if(isFort[i]){
            minDist[i] = 0;
            minDistFort[i] = i;

            q.push({0, i});
        }

    }

        //bfs din fiecare fortareata
    while(!q.empty()){

        pair<int,int> p = q.top();
        q.pop();



        if(!visited[p.second]){


            for(int i=0;i<lista[p.second].size();i++){

                pair<int,int> y = lista[p.second][i];

                if(!visited[y.first]) {
                    if (minDist[y.first] < p.first + y.second) {
                        minDist[y.first] = p.first + y.second;
                        minDistFort[y.first] = minDistFort[p.second];

                        q.push({minDist[y.first], y.first});
                    } else if (minDist[y.first] == p.first + y.second) {

                        minDistFort[y.first] = min(minDistFort[p.second], minDistFort[y.first]);
                    }
                }
            }
            visited[p.second] = 1;
        }
    }


    for(int i=1;i<=n;i++){
        if(isFort[i]==1)
            fout<<"0 ";
        else
            fout<<minDistFort[i]<<" ";

    }

}