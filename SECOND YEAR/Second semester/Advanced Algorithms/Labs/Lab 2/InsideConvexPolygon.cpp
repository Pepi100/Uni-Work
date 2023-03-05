#include <iostream>
#include <bits/stdc++.h>

using namespace std;




struct Pt{
    long long x,y;
}p, s;


long long determinant(Pt a, Pt b, Pt c){
    return b.x * c.y + a.x * b.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
    // det < 0 -> la dreapta
}

int isBetween(Pt a, Pt b, Pt c){
    if(determinant(a,b,c) == 0){
        if(min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y) )
            return 1;
    }
    return 0;
}

bool comp(Pt a, Pt b){
    return a.x < b.x;
}


class Polygon{
private:
    int n;
    vector<Pt> points;
    Pt leftMost, rightMost;

public:
    Polygon() =default;

    int getN() const {
        return n;
    }

    const vector<Pt> &getPoints() const {
        return points;
    }

    const Pt &getLeftMost() const {
        return leftMost;
    }

    const Pt &getRightMost() const {
        return rightMost;
    }

    void read(){
        cin>>n;
        Pt p;
        for(int i=1;i<=n;i++){
            cin>>p.x>>p.y;
            points.push_back(p);

            if(i ==1 ){
                leftMost = p;
                rightMost = p;
            }else{
                if( leftMost.x > p.x)
                    leftMost = p;
                if( rightMost.x > p.x)
                    rightMost = p;
            }
        }
    }

    int position(Pt x) {
        //https://www.youtube.com/watch?v=aoxOPx2BIHE

        int mid;
        int st = 0;
        int dr = n - 1;

        while (st < dr) {

            mid = st + (dr - st) / 2;


        }

        return 0;

    }

    int positionSlow(Pt x){
        // trecem prin toate muchiile si verificam daca se afla de aceeasi parte a lor

        int k =1;

        for(int i=1;i<n;i++)
        {


            if(determinant(points[i-1], points[i], x) == 0)
                k = 0;

            if(determinant(points[i-1], points[i], x) < 0)
                return -1;
        }

        return k;
    }


};

int main()
{

    Polygon p;
    p.read();

    // rezolvare
    int m;
    cin>>m;

    Pt q;
    while(m--){
        cin>>q.x>>q.y;
        int rez = p.positionSlow(q);
//        int rez = p.position(q);

        switch (rez) {
            case 1: cout<<"INSIDE\n";
                break;
            case 0: cout<<"BOUNDARY\n";
                break;
            default: cout<<"OUTSIDE\n";

        }

    }





}