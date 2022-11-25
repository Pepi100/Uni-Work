#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;


int n;
char s[200][200];

vector<vector<int>> muchii;

stack<int> st;
vector <int> indegrees(30,0);

vector <int> ordine;

int comp(char s1[200], char s2[200]){
    for(int i=0;i<= strlen(s1);i++){
        if(s1[i]!=s2[i]) return i;
    }

    return -1;
}




int main() {
    cin>>n;
    cin.get();
    for(int i=1;i<=n;i++){
        cin>>s[i];

    }

//comparam toate si adaugam nodurile in graf

    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int k= comp(s[i],s[j]);
            if(k!= -1){
                muchii[s[i][k]-'a'].push_back(s[j][k]-'a');
                indegrees[s[j][k]-'a']++;
            }
        }
    }



    for(int i=0;i<26;i++){
        if(indegrees[i] == 0){
            st.push(i);
        }
    }

    while(st.size()){

    }






    return 0;
}
