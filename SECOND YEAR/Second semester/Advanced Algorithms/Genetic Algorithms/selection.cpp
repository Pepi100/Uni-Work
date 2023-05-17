#include <iostream>
#include <iomanip>
using namespace std;


double fitness(int a, int b, int c, double x){
    return a*x*x + b * x + c;
}

int main() {
    int a, b,c, n;
    double sum = 0, actual=0.0;
    double v[100];
    cin>>a>>b>>c;
    cin>>n;

    for(int i=0; i< n; i++){
        cin>>v[i];
        v[i]=fitness(a,b,c,v[i]);
        sum += v[i];

    }


    for(int i=0; i< n; i++){
//        cout<<fixed<<setprecision(6)<<actual<<'\n';
        cout<<actual<<'\n';
        actual += (v[i]/sum);
    }

    cout<<setprecision(6)<<fixed<<1.0;



    return 0;
}
