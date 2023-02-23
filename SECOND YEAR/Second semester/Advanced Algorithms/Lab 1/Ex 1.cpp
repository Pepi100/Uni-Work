#include <iostream>


using namespace std;

//11 12 13
//21 22 23
//31 32 33

int A[4][4];

int main() {
    long long t, det;
    A[1][1] = A[1][2] = A[1][3] = 1;
    cin>>t;
    while(t--){
        cin>>A[2][1]>>A[3][1];
        cin>>A[2][2]>>A[3][2];
        cin>>A[2][3]>>A[3][3];

        det = A[2][2] * A[3][3] + A[2][1] * A[3][2] + A[2][3] * A[3][1] - A[2][2] * A[3][1] - A[2][3] * A[3][2] - A[2][1] * A[3][3];

        if (det == 0){
            cout<< "TOUCH\n";
        }else{
            if(det > 0)
                cout<< "LEFT\n";
            else
                cout<< "RIGHT\n";

        }
    }
    return 0;
}

