#include <iostream>


using namespace std;

int main() {
    int l, i;
    char v[2][100];
    cin>>l;
    for(int crom = 0; crom < 2; crom++){
        for(int chr = 0; chr < l;chr++){
            cin>>v[crom][chr];
        }
    }

    cin>>i;

    for(int crom = 0; crom < 2; crom++){
        for(int chr = 0; chr < l; chr++){
            cout<<v[(crom+(chr>=i))%2][chr];
        }
        cout<<'\n';
    }


    return 0;
}
