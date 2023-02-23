#include <iostream>


using namespace std;

//11 12 13
//21 22 23
//31 32 33

int A[4][4];

long long determinant(){
    return A[2][2] * A[3][3] + A[2][1] * A[3][2] + A[2][3] * A[3][1] - A[2][2] * A[3][1] - A[2][3] * A[3][2] - A[2][1] * A[3][3];

}

int main() {
    long long t, det;
    int i1, i2;
    int st = 0, dr = 0, fr = 0;
    A[1][1] = A[1][2] = A[1][3] = 1;
    cin>>t;
    cin>>A[2][1]>>A[3][1];
    cin>>A[2][2]>>A[3][2];
    t=t-2;
    i1 = A[2][1];
    i2 = A[3][1];
    while(t--){
        cin>>A[2][3]>>A[3][3];

        det = determinant();
        if (det == 0){
            fr ++;
        }else{
            if(det > 0)
                st++;
            else
                dr++;

        }

        A[2][1] = A[2][2];
        A[3][1] = A[3][2];

        A[2][2] = A[2][3];
        A[3][2] = A[3][3];


    }

    A[2][3] = i1;
    A[3][3] = i2;

    det = determinant();
    if (det == 0){
        fr ++;
    }else{
        if(det > 0)
            st++;
        else
            dr++;

    }

    cout<<st<<" "<<dr<<" "<<fr;
    return 0;
}

