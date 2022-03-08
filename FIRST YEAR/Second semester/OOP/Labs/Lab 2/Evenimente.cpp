#include <iostream>
#include "vector"
#include <algorithm>

using namespace std;

class Data {
private:
    int an, luna, zi;
public:
    Data(int an, int luna, int zi) : an(an), luna(luna), zi(zi) {}

    int getAn() const {
        return an;
    }

    void setAn(int an) {
        Data::an = an;
    }

    int getLuna() const {
        return luna;
    }

    void setLuna(int luna) {
        Data::luna = luna;
    }

    int getZi() const {
        return zi;
    }

    void setZi(int zi) {
        Data::zi = zi;
    }

    const int compare ( Data d){
        //-1 daca prima este mai mica
        // 0 daca sunt egale
        //1 daca prima este mai mare
        if( an == d.getAn() && luna == d.getLuna() && zi == d.getZi() ) return 0;
        if(an < d.getAn()){
            return -1;
        }else{
            if(luna < d.getLuna()){
                return -1;
            }else{
                if(zi < d.getZi()){
                    return -1;
                }
            }
            return 1;
        }

    }

};

class Event {
private:
    Data start, end;
    string name;
public:
    Event(const Data &start, const Data &anEnd, const string &name) : start(start), end(anEnd), name(name) {}

    const Data &getStart() const {
        return start;
    }

    void setStart(const Data &start) {
        Event::start = start;
    }

    const Data &getEnd()  {
        return end;
    }

    void setEnd(const Data &End) {
        end = End;
    }


    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Event::name = name;
    }

    void citire(){
        int s1,s2,s3,e1,e2,e3;
        cout<<"Citire data start: \n";
        cin>>s1>>s2>>s3;
        cout<<"Citire data end: \n";
        cin>>e1>>e2>>e3;
        cin.get();

        Data _start(s1,s2,s3), _end(e1,e2,e3);
        string _nume;
        cin>>_nume;
        name = _nume;
        start = _start;
        end = _end;
    }

    void afisare(){
        cout<<"Nume: "<<name<<'\n';
        cout<< "Inceput: "<<start.getZi()<<"."<<start.getLuna()<<"."<<start.getAn()<<"\n";
        cout<< "Sfarsit: "<<end.getZi()<<"."<<end.getLuna()<<"."<<end.getAn()<<"\n";
    }
};

void sortare( vector<Event> v ){
    int ok =1;
    int p=1;
    while(ok ==1){
        ok =0;
        for(int i=0;i<v.size()-p;i++){
            Data d = v[i].getEnd();
            if( d.compare(v[i+1].getEnd()) == 1) {
                swap(v[i],v[i+1]);
            }
        }
    }

}

int main() {


}


