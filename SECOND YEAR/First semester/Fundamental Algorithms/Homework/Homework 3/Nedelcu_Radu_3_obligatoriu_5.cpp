#include <bits/stdc++.h>


using namespace std;


class Solution {
public:



    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int fullmask = (1<<n)-1;

        unordered_map<int, vector<int>> a;

        //transformam graph ul primit intr-un dictionar
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                a[i].push_back(graph[i][j]);
            }
        }




        vector<vector<int>> dist(1<<n, vector<int>(n, -1));
        queue<vector<int>> q;



        //adaugam in stiva toate nodurile, impreuna cu mask ul de inceput, pentru a porni un bfs din fiecare
        for (int i = 0; i < n; i++) {

            q.push({i, 0 | (1<<i)});
            dist[0 | (1<<i)][i] = 0;
        }

        //incepem bfs
        while (!q.empty()) {

            for (int j = 0;j < q.size(); j++) {
                vector<int> actual = q.front();
                q.pop();
                int nod = actual[0];
                

                if (actual[1] == fullmask) {

                    //primul path gasit prin bfs va fi si cel mai scurt
                    return dist[actual[1]][nod];
                }

                if (a.count(nod) ){
                    for (int i=0; i< a[nod].size();i++) {

                        int masca = actual[1] | (1<<a[nod][i]);

                        if (dist[masca][a[nod][i]] != -1) {
                            continue;
                        }

                        q.push({a[nod][i], masca});
                        dist[masca][a[nod][i]] = dist[actual[1]][nod] + 1;

                    }
                }
            }
        }
        return -1;



    }
};


int main(){

Solution s;

vector<vector<int>> g = {{1},{0,2,4},{1,3,4},{2},{1,2}};

cout<<s.shortestPathLength(g);





}




