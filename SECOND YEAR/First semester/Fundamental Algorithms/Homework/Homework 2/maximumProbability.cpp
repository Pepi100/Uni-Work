
#include <iostream>
#include <vector>
#include <queue>

using namespace std;



class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {

        //construim o lista de adiacenta
        //pentru fiecare nod memoram o lista de perechi (nod, probabilitate)
        vector<vector<vector<double>>> list(n);
        for(int i=0;i<edges.size();i++){
            list[edges[i][0]].push_back({(double)edges[i][1],succProb[i]});
            list[edges[i][1]].push_back({(double)edges[i][0],succProb[i]});
        }

        priority_queue<vector<double>> queue;


        double probability[n];
        for(int i=0;i<n;i++){
            probability[i]=0;
        }
        probability[start] = 1;
        queue.push({1,(double)start});

        //dijkstra cu priority queue
        while(queue.empty() == false){

            vector<double> p = queue.top();
            queue.pop();



            for(int i=0;i< list[p[1]].size();i++){

                vector<double> v = list[p[1]][i];
                if(p[0]*v[1] > probability[(int)v[0]]){

                    probability[(int)v[0]] = p[0]*v[1];
                    queue.push({p[0]*v[1],v[0]});

                }
            }
        }

        return probability[end];
    }
};


int main(){

    int n,m, start, end;
    cin>>n>>m;
    vector<vector<int>> edges;
    vector<double> prob(m);
    int x, y;

    for(int i=0;i<m;i++){
       vector<int> temp(2);

       cin>>temp[0]>>temp[1]>>prob[i];
       edges.push_back(temp);

    }

    cin>>start>>end;


    Solution s;

    cout<<s.maxProbability(n, edges, prob, start, end);

    return 0;
}