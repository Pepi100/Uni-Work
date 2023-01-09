#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

//        cout<<n<<" "<<m<<endl;

        int a[n+1][m+1];
        //bordare
        for(int i=0;i<=n;i++){
            a[i][m]=0;
        }
        for(int i=0;i<=m;i++){
            a[n][i]=0;
        }

        for(int i = n-1; i>=0;i--){

            for(int j = m-1; j>=0; j--){
                if(text1[i] == text2[j])
                    a[i][j] = 1+a[i+1][j+1];
                else
                    a[i][j] = max(a[i][j+1], a[i+1][j]);
            }
        }

        //debug
//
//        for(int i=0; i<=n;i++){
//
//            for(int j=0; j<=m;j++)
//                cout<<a[i][j]<<" ";
//
//            cout<<endl;
//
//        }

        return a[0][0];

    }
};


int main(){

Solution s;

cout<<s.longestCommonSubsequence("abcde", "ace");




}




