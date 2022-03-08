
 <iostream>

using namespace std;


class Bilet{
private:
    string name;
    bool firstClass;

public:
     string getName(){
        return name;
    }

    bool getfirstClass(){
        return firstClass;
    }

    void setName(string _name){
         name = _name;
    }

    void setFirstClass(bool _firstClass){
         firstClass= _firstClass;
     }

     Bilet(){
         name = "";
         firstClass = false;
     }

    Bilet(string _name, int _firstClass){
        name = _name;
        firstClass= _firstClass;
    }

    void citeste(){
         string _name;
         bool _firstClass;
         getline(cin, _name);
         cin>>_firstClass;
         name = _name;
         firstClass = _firstClass;
     }

};


void statisticaZboruri(int n, Bilet bilete[]){
    int cl1=0, cl2=0;
    for(int i=0;i<n;i++){
        if(bilete[i].getfirstClass())
            cl1++;
        else cl2++;
    }
    cout<<"Avem "<<cl1<< " bilete la clasa I, dar si "<<cl2<<" bilete la alte clase.";

}

int main() {

    Bilet bilete[4] = {Bilet("Popescu Leuraș", true),
                      Bilet("Manolescu Alexandra", true),
                      Bilet("Popescu Mănăila", false)};
    bilete[3].citeste();
    statisticaZboruri(4, bilete);


    return 0;
}
