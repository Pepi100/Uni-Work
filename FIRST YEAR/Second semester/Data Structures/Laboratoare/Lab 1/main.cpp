#include <iostream>
#include <vector>

using namespace std;

// 0 1 2 3 4 5 6 7 8 9
// 1 9 2 8 3 7 4 6 5 5

int existsAlternate(vector<int>& a, int e){
    //cautare pare
    int left = 0;
    int right = (a.size()-1)/2*2;
    int poz = a.size()-1;
    while(left < right){
        int middle = (left + right)/2/2*2;
        if(a[middle]>=e){
            poz = middle;
            left = middle;
        }else{
            right = middle;
        }
    }

    if(a[poz] == e){
        return poz;
    }

    //cautare impare
    left = 1;
    right = (a.size()-1) + (a.size()%2);
    poz = a.size()-1;

    while(left < right){
        int middle = (left + right)/2 + ((left + right)/2 +1)%2-2;
        if(a[middle]<=e){
            poz = middle;
            left = middle;
        }else{
            right = middle;
        }
    }

    if(a[poz] == e){
        return poz;
    }

    return -1;

}


int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    cout<<existsAlternate(a, 6);


    return 0;
}
