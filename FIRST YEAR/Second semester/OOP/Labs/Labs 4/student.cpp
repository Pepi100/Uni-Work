#include <iostream>
#include <vector>
using namespace std;


class Student{
private:
    string nume;
    string prenume;
    int grupa;
    int semigrupa;
    vector<int> note;
public:
    Student() {
        prenume = "";
        nume = "";
        grupa = 0;
        semigrupa = 0;
        note ={};
    };

    Student( string _nume, string _prenume, int _grupa, int _semigrupa, vector<int> _note){
        prenume = _prenume;
        nume = _nume;
        grupa = _grupa;
        semigrupa = _semigrupa;
        note = _note;
    }

    void operator+=(int notaNoua){
        note.push_back(notaNoua);

    }

    friend ostream &operator<<(ostream &os, const Student &student);
    friend istream &operator>>(istream &is, Student &student);
};

ostream &operator<<(ostream &os, const Student &student) {
    os << "Nume: " << student.nume << " Prenume: " << student.prenume << " Grupa: " << student.grupa
       << " Semigrupa: " << student.semigrupa << " Note: ";
    for(int i =0; i<student.note.size(); i++){
        os << student.note[i]<<" ";
    }
    return os;
}

istream &operator>>(istream &is, Student &student) {
    cout<<"Nume: ";
    is >>student.nume;
    cout<<"\nPrenume: ";
    is >> student.prenume;
    cout<<"\nGrupa: ";
    is >> student.grupa;
    cout<<"\nSemigrupa: ";
    is >> student.semigrupa;
    int nrNote, x;
    cout<<"\nNumar note: ";
    is >> nrNote;
    cout<<"\nNote: ";
    for(int i=0; i<nrNote; i++){
        is >> x;
        student.note.push_back(x);
    }
    return is;
}




int main() {

    Student s;

    cin >> s;
    cout << s;
}



