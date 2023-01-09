#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    string longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();



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

        //calculam lcs

        string lcs = "";

        int i=0, j=0;

        while(i<n && j <m){
            if(text1[i] == text2[j]){
                lcs += text1[i];
                i++;
                j++;
            }else{
                if(a[i+1][j] > a[i][j+1]){
                    i++;
                }else{
                    j++;
                }

            }
        }

        return lcs;


    }

    string shortestCommonSupersequence(string str1, string str2) {
        string lcs =   longestCommonSubsequence(str1, str2);


        string rez="";
        int i=0, j=0,k=0; // pozitiile in str1, str2, lcs

        while(lcs[k]){
            while(str1[i] != lcs[k]){
                rez += str1[i];
                i++;
            }

            while(str2[j] != lcs[k]){
                rez += str2[j];
                j++;
            }


            rez+=lcs[k];
            i++;
            j++;
            k++;
        }

        while(str1[i]){
            rez += str1[i];
            i++;
        }

        while(str2[j]){
            rez += str2[j];
            j++;
        }



        return rez;

    }
};


int main(){

Solution s;


cout<<s.shortestCommonSupersequence("abac", "cab")<<endl;




}




