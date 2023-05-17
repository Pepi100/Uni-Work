#include <bits/stdc++.h>
using namespace std;


struct interval{
    int l;
    double a,b;


    double step;
}domain;


class Chromosome{
private:
    char genes[100];
    double value;

    void updateValue(){
        int place=0;

        long long pow = 1;
        for(int i=domain.l-1; i>=0;i--){
            place += (genes[i]-'0')*pow;
            pow*=2;
        }

        value = domain.a + place* domain.step;


    }

    void updateGenes(){
        int place=0;
        while(domain.a + domain.step* (place+1) <= value){
            place++;
        }

        // the number of the inverval was found, now be need to tranform in to binary and put the rezult into the vector

        int aux[100];


        int i = 0;
        while (place > 0) {
            aux[i] = place % 2;
            place = place / 2;
            i++;
        }

        while(i<domain.l){
            aux[i] = 0;
            i++;
        }

//        print aux
//        cout<<"AUX: ";
//        for(int j=0;j<i;j++){
//            cout<<aux[j];
//        }
//        cout<<endl;


        for (int j =0; j<domain.l; j++){
            genes[j]='0'+ aux[domain.l-j-1];
        }

    }

public:

    //constructors
     Chromosome(char *_genes)  {
        strcpy(genes, _genes);

        updateValue();

    }

     Chromosome(double value)  {
         this->value = value;
         updateGenes();

    }

    //getters
    const char *getGenes() const {
        return genes;
    }

    double getValue() const {
        return value;
    }




};

class Generation{
private:
    Chromosome population[50];
    int size;
    int precision;
};

//double a,b;
int p,m;


int main() {
    cin >> domain.a >> domain.b >> p >> m;
    domain.l=ceil(log2((domain.b - domain.a) * pow(10, p) ));
    domain.step = (domain.b - domain.a) / pow(2, domain.l);


    char v[5];
while(m--){
    cin>>v;
    if(strstr(v, "TO") != NULL){
        //TO
        double x;
        cin>>x;
        cin.get();
        Chromosome ch(x);

        cout<<ch.getGenes()<<'\n';


    }else{
        //FROM

        char gene[100];
        cin>>gene;
        Chromosome ch(gene);

        cout<<ch.getValue()<<'\n';


    }

}


}



