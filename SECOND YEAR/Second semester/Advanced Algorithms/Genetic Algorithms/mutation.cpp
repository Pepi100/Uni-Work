#include <iostream>
using namespace std;


int main() {
    int l, k, chr;
    char crom[100];
    cin>>l>>k;
    cin.get();
    cin>>crom;
    for(int i=0; i<k;i++){
        cin>>chr;
        crom[chr] = '0' + (crom[chr]-'0'+1)%2;
    }

    cout<<crom;

    return 0;
}
