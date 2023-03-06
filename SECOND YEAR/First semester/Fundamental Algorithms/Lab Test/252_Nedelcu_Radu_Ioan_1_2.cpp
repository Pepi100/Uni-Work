#include <fstream>
#include <iostream>
#include <vector>

using namespace std;


ifstream fin("graf.in");


long long sum[15005];
int visited[15005];
vector<vector<pair<int, int>>> lista;
int k;

void dfs( int node){
    visited[node] = 1;


//    cout<<node;
    for(int i=0;i<lista[node].size();i++){

        if(visited[lista[node][i].first] == 0 && lista[node][i].second <= k) {
            dfs(lista[node][i].first );

            if(sum[node] < lista[node][i].second + sum[lista[node][i].first]){
            sum[node] = lista[node][i].second + sum[lista[node][i].first];
        }

        }



    }



}



int main(){
    int n,m,a,b,c;
    long long maximum = -9999999999999;
    int x;


        fin>>n>>m;


        for(int i=0;i<n;i++){

            vector<pair<int, int>> temp;
            lista.push_back(temp);
            visited[i]=0;
        }


        for(int i=1;i<=m;i++){
               fin>>a>>b>>c;
               lista[a].push_back({b, c});
        }
        fin>>k;

        maximum = -9999999;
        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                dfs( i);
            }
            if(maximum < sum[i]){
                maximum = sum[i];
                x= i;
            }

        }

        // am gasit graful, acum trebuie sa reconstruim
        //cout<<sum[0]<<" "<<sum[2]<<" "<<sum[4];
        cout<<"Drumul este:\n";
        while(sum[x] != 0){
            cout<<x<<" ";

            for(int i=0;i<lista[x].size();i++){
                if( sum[x] - lista[x][i].second == sum[lista[x][i].first])
                    {
                        x= lista[x][i].first;
                        break;
                    }

            }

        }
        cout<<x;

        //cout<<maximum<<'\n';







    return 0;

}
