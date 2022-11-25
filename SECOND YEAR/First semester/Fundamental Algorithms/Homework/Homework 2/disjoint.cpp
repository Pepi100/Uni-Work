#include <fstream>
#include <iostream>
#include <vector>


using namespace std;

ifstream fin ("disjoint.in");
ofstream fout ("disjoint.out");

int parents[100002];

int getParent(int n){
    int copy = n;

    while(parents[n] != 0){
        n = parents[n];
    }
    int root = n;
    //parcurgem inca o data pentru a optimiza

    n= copy;
    while(parents[n] != 0){
        copy = parents[n];
        parents[n] = root;
        n=copy;
    }




    return root;
}


int main() {

    int n, m, type,x,y;
    fin>>n>>m;

    while(m--){
        fin>>type>>x>>y;

        if(type == 1){
//            cout<<getParent(x)<< " "<< getParent(y)<<endl;
            if(getParent(x)!= getParent(y)) parents[getParent(x)] = getParent(y);

        }else{
            if(getParent(x) == getParent(y)){
                fout<<"DA\n";
            }else{
                fout<<"NU\n";
            }
        }

    }





    return 0;
}
