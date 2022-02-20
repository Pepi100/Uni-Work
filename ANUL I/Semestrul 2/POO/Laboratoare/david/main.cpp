#include <iostream>

using namespace std;

int main()
{
    int n,x;
    cin>>n;

    for(int k=0;k<n;k++{
        cin>>x;
        for(int i=0;i<x;i++){
            for(int j=0;j<x;j++){
                if(k%2)cout<<(i*j)%x<<" ";
                else cout<<(i+j)%x<<" ";
            }
            cout<<"\n";
    }

    }

    return 0;
}
