#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

ifstream fin("easygraph.in");
ofstream fout("easygraph.out");

long long sum[15005];
int visited[15005], nodes[15005];
vector<vector<int>> list;

void dfs( int node){
    visited[node] = 1;

    sum[node] = nodes[node];
//    cout<<node;
    for(int i=0;i<list[node].size();i++){

        if(visited[list[node][i]] == 0) {
            dfs(list[node][i] );

        }

        if(sum[node] < nodes[node] + sum[list[node][i]]){
            sum[node] = nodes[node] + sum[list[node][i]];
        }

    }



}



int main(){
    int t,n,m,a,b;
    long long maximum = -9999999999999;

    fin>>t;
    while(t--){
        fin>>n>>m;
        list.clear();
        vector<int> temp;
        list.push_back(temp);
        for(int i=1;i<=n;i++){
            fin>>nodes[i];

            vector<int> temp;
            list.push_back(temp);
            visited[i]=0;
        }


        for(int i=1;i<=m;i++){
               fin>>a>>b;
               list[a].push_back(b);
        }


        maximum = -9999999;
        for(int i=1;i<=n;i++){
            if(visited[i] == 0){
                dfs( i);
            }
            maximum = max(maximum, sum[i]);

        }

        fout<<maximum<<'\n';





    }

    return 0;

}