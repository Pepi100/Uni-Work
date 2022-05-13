#include  <iostream>
#include <vector>


using namespace std;


template<typename T>  // T va fi tipul generic, adica la rulare add(3,2) determina T->int, la rulare add(string(“a”),string(“b”)) determina T->string etc.
T add(T a, T b){
    return a + b;
}

template<typename T>
istream& operator>>(istream& is, vector<T> &v){
   int nr_elem;
   T elem;
   cout<<"Introduceti numarul de elemente: ";
   is>>nr_elem;
   cout<<"Introduceti cele "<<nr_elem<<" elemente separate prin ENTER: ";
   for(int i=1;i<=nr_elem;i++){
       is>>elem;
       v.push_back(elem);
   }
   return is;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T> v){
    os<<"Vectorul contine elementele: ";
    for(int i=0; i<v.size();i++){
        os<< v[i]<<" ";
    }
    return os;
}





int main() {

    vector<string> vs;
    cin >> vs;
    cout << vs;

}
