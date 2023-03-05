#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Pt{
    long long x,y;
}p;


long long determinant(Pt a, Pt b, Pt c){
    return b.x * c.y + a.x * b.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

bool comp(Pt a, Pt b){
    if( a.x == b.x)
        return a.y <b.y;
    return a.x < b.x;
}

int main()
{
    long long n;
    vector<Pt> v;
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>p.x>>p.y;
        v.push_back(p);
    }

    sort(v.begin(), v.end(), comp);

    vector <Pt>r;


    for(long long i=0; i<n; i++){

        r.push_back(v[i]);

        if(r.size()>=3){
            while( r.size()>=3 && determinant(r[r.size()-3], r[r.size()-2], r[r.size()-1]) <= 0){
                r[r.size()-2] = r[r.size()-1];
                r.pop_back();
            }

        }

    }



    vector <Pt> r2;

    for(long long i=0; i<n; i++){

        r2.push_back(v[i]);

        if(r2.size()>=3){
            while( r2.size()>=3 && determinant(r2[r2.size()-3], r2[r2.size()-2], r2[r2.size()-1]) >= 0){
                r2[r2.size()-2] = r2[r2.size()-1];
                r2.pop_back();
            }

        }

    }
    long long sol = r.size() + r2.size()-2;
    cout<<sol<<'\n';
    for(long long i=0; i<r.size(); i++){
        cout<<r[i].x<<" "<<r[i].y<<'\n';
    }


    for(long long i=r2.size()-2; i>0; i--){
        cout<<r2[i].x<<" "<<r2[i].y<<'\n';
    }


return 0;

}