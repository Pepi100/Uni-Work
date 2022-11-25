#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//sortare topoligica
//Pentru a merge la un curs este necesar sa parcurgem inainte toate cursurile pe care aceasta il necesita
//Astfel, vom putea parcurge initial doar cursurile care nu au unul necesar inainte
//De din acestea pornim o parcurgere de tip BFS

//course schedule

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> predecesori(numCourses+1);
        vector<vector<int>> succesori(numCourses+1);

        for(int i=0;i< prerequisites.size();i++){
            predecesori[prerequisites[i][0] ].push_back(prerequisites[i][1]);
            succesori[prerequisites[i][1] ].push_back(prerequisites[i][0]);
        }

        queue<int> coada;

        //adaugam in coada toate cursuile care nu depind de altele

        for(int i=0;i<numCourses;i++){
            if(predecesori[i].size()==0)
                coada.push(i);
        }

        vector<int> rez;

        while(!coada.empty()){
            int curent = coada.front();
            coada.pop();
            rez.push_back(curent);
            //parcurgem toate nodurile care necesitau nodul curent si eliminam acea dependenta

            for(int i=0;i< succesori[curent].size();i++){
                int s = succesori[curent][i];
                for(int j=0;j<predecesori[s].size();j++){
                    if(predecesori[s][j]==curent){
                        predecesori[s].erase(predecesori[s].begin()+j );
                    }
                }
                // daca aceste noduri au acum 0 predecesori ramasi el putem aduga la coada

                if(predecesori[s].size() == 0)
                    coada.push(s);

            }


        }
        if(rez.size() == numCourses) return rez;
        return {};

    }

};

int main() {
    int n, m;
    vector<vector<int>> d;
    cin>>n>>m;



    int a, b;

    for(int i=1;i<=m;i++){

        cin>>a>>b;
        d.push_back({a,b});
    }

    Solution s;
    vector<int> rez = s.findOrder(n,d);

    for(int i=0;i<rez.size();i++)
        cout<<rez[i]<<" ";



    return 0;
}
/*


4 4
1 0
2 0
3 1
3 2

4 5
1 0
2 0
3 1
3 2
2 3


 */