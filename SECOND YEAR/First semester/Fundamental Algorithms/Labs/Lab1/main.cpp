#include <iostream>
#include <vector>

using namespace std;


class Solution {
    vector<int > d;
    vector<pair<int, int>> c;
    // + tinut minte
public:

    void bfs(int poz, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {

        if(c[poz][1] == 1 ) {//rosu
            for(int i=0;i<redEdges.size();i++) {
                if(redEdges[i][0] == c[poz][0]){
                     //va continua pe albastru

                    c.push_back( pair<int, int> (redEdges[i][1],2) );
                }

            }
        }else{
            for(int i=0;i<blueEdges.size();i++) {
                if(blueEdges[i][0] == c[poz][0]){
                    vector<int> c1;
                    c1.push_back(blueEdges[i][1]);
                    c1.push_back(1); //va continua pe rosu

                    c.push_back(c1);
                }

            }

        }

        if(poz<c.size())
        bfs(poz+1, redEdges, blueEdges);

    }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
            d.push_back(0);
            for(int i=1;i<n;i++)
                d.push_back(-1);
            vector<int> c1;
            c1.push_back(0);
            c1.push_back(0);

            c.push_back(c1);

            bfs(0, redEdges, blueEdges);



         return d;
    }


};



int main() {
    Solution s;
    vector<int> r, b;



    vector<int> d = s.shortestAlternatingPaths(3);

    for(int i=0;i<d.size();i++){
        cout<<d[i]<<" ";
    }
}



