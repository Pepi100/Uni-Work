#include <bits/stdc++.h>
#define inf 20000000

using namespace std;




int main()
{
    int n;
    cin>>n;

    int a,b,c;
    double xMin = -inf;
    double yMin = -inf;
    double xMax = inf;
    double yMax = inf;



    while(n--){
        cin>>a>>b>>c;

        if(a ==0){
            if(b > 0){
                yMax = min(yMax, -1.0*c/b);
            }else{
                yMin = max(yMin, -1.0*c/b);
            }

        }else{

            if(a >0){
                xMax = min(xMax, -1.0*c/a);
            }else{

                xMin = max(xMin, -1.0*c/a);
            }


        }



    }


    //afisare

//    cout<<xMin<<" "<<xMax<<endl;
//    cout<<yMin<<" "<<yMax<<endl;

    if(xMax <= xMin || yMax <= yMin) {
        cout << "VOID";
        return 0;
    }else{
        if( xMin == -inf || yMin == -inf ||xMax == inf ||yMax == inf)
            cout<<"UNBOUNDED";
        else
            cout<<"BOUNDED";
    }


}

/*
-2 4
-3 0
0 -2
3
1 2
3 3
6 -1
*/