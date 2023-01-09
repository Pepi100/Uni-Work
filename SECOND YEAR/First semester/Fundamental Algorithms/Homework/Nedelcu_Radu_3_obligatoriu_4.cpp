#include <bits/stdc++.h>


using namespace std;


class Solution {
public:


    vector<vector<int>> rez;
    unordered_map<int, stack<int>> a;


    int length = 0,ok = 1;
    void bfs(int nod){
        if(rez.size() == length){
            ok =0;
        }

        while(!a[nod].empty() && ok){

            int aux = a[nod].top();
            a[nod].pop();

            bfs(aux);
            rez.push_back({nod, aux});
//            if(a[nod][i] != -1) {
//
//
//                int aux = a[nod][i];
//                a[nod][i] = -1;
//
//                bfs(aux);
//                a[nod][i] = aux;
//                rez.pop_back();
//
//            }
        }

    }


    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, int> grad;
        length = pairs.size();

        a.reserve(length);



        for(int i=0;i<pairs.size();i++){

                grad[pairs[i][0]]++;
                a[pairs[i][0]].push(pairs[i][1]);
                grad[pairs[i][1]]--;



        }

        //cautam un nod de start
        int start = -1;
        for(auto t : grad){
            if( t.second == 1 )
                start=t.first;
        }
        if(start == -1)
            start = a.begin()->first;



        //bfs
       bfs(start);


        for(auto t: rez){
            cout<<t[0]<<" "<<t[1]<<" ";
        }
        reverse(rez.begin(), rez.end());
        return rez;
    }
};


int main(){

Solution s;

vector<vector<int>> pairs = {{5,1},{4,5},{11,9}, {9,4}};
    vector<vector<int>> pairs2 = {{17,18},{18,10},{10,18}};
s.validArrangement(pairs2);




}




