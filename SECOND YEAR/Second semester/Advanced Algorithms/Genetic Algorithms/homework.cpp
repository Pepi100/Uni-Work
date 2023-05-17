#include <bits/stdc++.h>
#include <ctime>
#include <random>
#define ELITISM true
#define CROSSOVER_PROB 0.25
#define MUTATION_PROB 0.1

using namespace std;

ofstream fout("evolution.txt");
ifstream fin("input.in");




struct interval{
    double a,b;
    int p;

    int l;
    double step;
}domain;

struct function{
    int a,b,c;
}f;

void buildDomain(){
    domain.l=ceil(log2((domain.b - domain.a) * pow(10, domain.p) ));
    domain.step = (domain.b - domain.a) / pow(2, domain.l);
}




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

    double getFitness() const{
        return f.a*value * value + f.b*value + f.c;
    }

    //setters

    void setGenes(char *_genes){
        strcpy(genes, _genes);
        updateValue();
    }

    //mutation

    void rareMutation(){
        //generate random position
        int p=rand()%domain.l;

        genes[p] = (genes[p]-'0'+1)%2 + '0';
        updateValue();

    }


};

class Generation{
private:
    vector <Chromosome> population ;
    int size;
    int precision;


    void crossover(int a, int b, int i){
        char v[2][100];
        char aux[2][100];
        strcpy(v[0], population[a].getGenes());
        strcpy(v[1], population[b].getGenes());

        for(int crom = 0; crom < 2; crom++){
            for(int chr = 0; chr < domain.l; chr++){
                aux[crom][chr] = v[(crom+(chr>=i))%2][chr];
            }
            aux[crom][domain.l] = '\0';
        }

        population[a].setGenes(aux[0]);
        population[b].setGenes(aux[1]);
    }


    void crossover(int a, int b, int c, int i){
        char v[3][100];
        char aux[3][100];
        strcpy(v[0], population[a].getGenes());
        strcpy(v[1], population[b].getGenes());
        strcpy(v[2], population[c].getGenes());

        for(int crom = 0; crom < 3; crom++){
            for(int chr = 0; chr < domain.l; chr++){
                aux[crom][chr] = v[(crom+(chr>=i))%3][chr];
            }
            aux[crom][domain.l] = '\0';
        }

        population[a].setGenes(aux[0]);
        population[b].setGenes(aux[1]);
        population[c].setGenes(aux[2]);
    }

public:

    Generation(int n){
        size = n;



        for(int i=1; i<=n;i++){
            //random value between a and b;
            double value = rand() / (double) RAND_MAX * (domain.b - domain.a) + domain.a;

            Chromosome c(value);
            population.push_back(c);
        }

    }

    //getters

    const vector<Chromosome> &getPopulation() const {
        return population;
    }

    int getSize() const {
        return size;
    }

    int getPrecision() const {
        return precision;
    }

    Chromosome getChromosome(int i) const{
        return population[i];
    }

    double getFitness() const{
        double sum = 0;
        for(auto c:population){
            sum += c.getFitness();
        }
        return sum;
    }

    Chromosome getBest() const{
        Chromosome aux = population[0];

        for(int i=1; i<population.size();i++){
            if(aux.getFitness() < population[i].getFitness())
                aux=population[i];
        }

        return aux;

    };

    //setters

    void setPopulation(const vector<Chromosome> &population) {
        Generation::population = population;
    }


    //selection

    void selectionWithPrint(){

        fout<<"\nSelection Probability: \n";
        double fit = getFitness();

        for(int i=0;i<getSize();i++){
            fout<<"  chromosome: "<<right << setw(3)<<i+1<<".  probability= "<<right << setw(11)<<population[i].getFitness()/fit<<"\n";
        }

        fout<<"\nSelection Probability Intervals: \n";
        double aux[getSize()+1];
        aux[0]=0;
        fout<<aux[0]<<" ";
        for(int i=0;i<getSize()-1;i++){
            aux[i+1]=aux[i] + population[i].getFitness()/fit;
            fout<<aux[i+1]<<" ";
        }
        aux[getSize()] = 1;
        fout<<aux[getSize()]<<'\n';

        //selectarea cromozomilor
        vector <Chromosome> popl;
        //criteriul elitist;

        if(ELITISM){
            popl.push_back(getBest());

            fout<<"The best choromose was automatically selected for crossover!\n";
        }

        while(popl.size() < getSize()){
            //generate random u;
            double u= rand() / (double) RAND_MAX;

            int left = 0, right = getSize();

            while(right-left >1){
                int mid = (right+ left)/2;

                if(u<aux[mid]){
                    right = mid;
                }else{
                    left=mid;
                }

            }

            fout<<"  u=" << setw(11)<<u<<"  selecting chromosome "<< setw(3)<<left+1<<'\n';
            popl.push_back(population[left]);

        }

        setPopulation(popl);

    }

    void selection(){


        double fit = getFitness();
        double aux[getSize()+1];

        aux[0]=0;

        for(int i=0;i<getSize()-1;i++){
            aux[i+1]=aux[i] + population[i].getFitness()/fit;
        }
        aux[getSize()] = 1;

        vector <Chromosome> popl;

        if(ELITISM){
            popl.push_back(getBest());
        }

        while(popl.size() < getSize()){
            //generate random u;
            double u= rand() / (double) RAND_MAX;

            int left = 0, right = getSize();

            while(right-left >1){
                int mid = (right+ left)/2;

                if(u<aux[mid]){
                    right = mid;
                }else{
                    left=mid;
                }

            }

            popl.push_back(population[left]);

        }

        setPopulation(popl);


    }


    //crossover
    void genCrossoverWithPrint(){


        queue <int> cross_selection;

        for(int i=0;i<getSize();i++){
            double u= rand() / (double) RAND_MAX;

            fout<<"  "<<right << setw(3)<<i+1<<".  "<<population[i].getGenes()<<"  val="<<right << setw(10)<<fixed<<setprecision(6)<< population[i].getValue()<<"  u= "<<right << setw(9)<<u;
            if(u<CROSSOVER_PROB){
                fout<< " < "<<CROSSOVER_PROB<<" SELECTED\n";
                cross_selection.push(i);
            }

            else fout<<'\n';
        }

        if(cross_selection.size() == 1){
            return;
        }

        while(cross_selection.size() != 3 && !cross_selection.empty()){
            int a = cross_selection.front();
            cross_selection.pop();

            int b = cross_selection.front();
            cross_selection.pop();

            int i= 1+rand()%(domain.l/2);
            fout<<setw(3)<<"Crossover between " << a+1<< " and "<<b+1<< " with crossover point "<<i+1<<"\n  Before:\n   ";

            for(int j=0;j<domain.l;j++){
                fout<<population[a].getGenes()[j];
                if(j==i){
                    fout<<'|';
                }
            }
            fout<<"\n   ";

            for(int j=0;j<domain.l;j++){
                fout<<population[b].getGenes()[j];
                if(j==i){
                    fout<<'|';
                }
            }

            crossover(a,b,i+1);

            fout<<"\n  After:\n   ";

            for(int j=0;j<domain.l;j++){
                fout<<population[a].getGenes()[j];
                if(j==i){
                    fout<<'|';
                }
            }
            fout<<"\n   ";

            for(int j=0;j<domain.l;j++){
                fout<<population[b].getGenes()[j];
                if(j==i){
                    fout<<'|';
                }
            }

            fout<<"\n";

        }

        if(cross_selection.size() == 3) {

            int a = cross_selection.front();
            cross_selection.pop();

            int b = cross_selection.front();
            cross_selection.pop();

            int c = cross_selection.front();
            cross_selection.pop();

            int i= 1+rand()%(domain.l/2);
            fout<<setw(3)<<"Crossover between " << a+1<<", "<<b+1<< " and "<<c+1<< " with crossover point "<<i+1<<"\n  Before:\n   ";

            for(int j=0;j<domain.l;j++){
                fout<<population[a].getGenes()[j];
                if(j==i){
                    fout<<'|';
                }
            }
            fout<<"\n   ";

            for(int j=0;j<domain.l;j++){
                fout<<population[b].getGenes()[j];
                if(j==i){
                    fout<<'|';
                }
            }

            fout<<"\n   ";

            for(int j=0;j<domain.l;j++){
                fout<<population[c].getGenes()[j];
                if(j==i){
                    fout<<'|';
                }
            }

            crossover(a,b,c,i+1);

            fout<<"\n  After:\n   ";

            for(int j=0;j<domain.l;j++){
                fout<<population[a].getGenes()[j];
                if(j==i){
                    fout<<'|';
                }
            }
            fout<<"\n   ";

            for(int j=0;j<domain.l;j++){
                fout<<population[b].getGenes()[j];
                if(j==i){
                    fout<<'|';
                }
            }
            fout<<"\n   ";
            for(int j=0;j<domain.l;j++){
                fout<<population[c].getGenes()[j];
                if(j==i){
                    fout<<'|';
                }
            }
            fout<<"\n";
        }
    }

    void genCrossover(){

        queue <int> cross_selection;

        for(int i=0;i<size;i++){
            double u= rand() / (double) RAND_MAX;
            if(u<CROSSOVER_PROB){
                cross_selection.push(i);
            }
        }

        if(cross_selection.size() == 1){
            return;
        }

        while(cross_selection.size() != 3 && !cross_selection.empty()){
            int a = cross_selection.front();
            cross_selection.pop();

            int b = cross_selection.front();
            cross_selection.pop();

            int i= 1+rand()%(domain.l/2);
            crossover(a,b,i+1);

        }

        if(cross_selection.size() == 3) {

            int a = cross_selection.front();
            cross_selection.pop();

            int b = cross_selection.front();
            cross_selection.pop();

            int c = cross_selection.front();
            cross_selection.pop();

            int i= 1+rand()%(domain.l/2);

            crossover(a,b,c,i+1);


        }

    }

    //mutation

    void mutationWithPrint(){
        //rare mutation
        for(int i=0;i<getSize();i++){
            double u= rand() / (double) RAND_MAX;

            fout<<"  "<<right << setw(3)<<i+1<<".  "<<population[i].getGenes()<<"  val="<<right << setw(10)<<fixed<<setprecision(6)<< population[i].getValue()<<"  u= "<<right << setw(9)<<u;
            if(u<MUTATION_PROB){
                fout<< " < "<<MUTATION_PROB<<" SELECTED\n";
                population[i].rareMutation();
            }
            else fout<<'\n';
        }
    }

    void mutation(){
        //rare mutation
        for(int i=0;i<getSize();i++){
            double u= rand() / (double) RAND_MAX;
            if(u<MUTATION_PROB){
                population[i].rareMutation();
            }

        }
    }




    //printing
    void printPopulation(){
        for(int i=0;i<size;i++){
            fout<<"  "<<right << setw(3)<<i+1<<".  "<<population[i].getGenes()<<"  val="<<right << setw(10)<<fixed<<setprecision(6)<< population[i].getValue()<<"  fitness= "<<right << setw(9)<<population[i].getFitness()<<"\n";
        }
    }

    void printStatus(){

        double avg=0;

        for(int i=0; i<size;i++)
            avg+=population[i].getFitness();
        avg=avg/size;
        fout<<"Best:  " <<right<<setw(12)<<getBest().getFitness();
        fout<<"    Average: "<<right<<setw(12)<<avg<<'\n';
    }


};




int main() {
    //citire
    int n, epochs;
    cin>>n;
    cin>>domain.a>>domain.b;
    cin>>f.a>>f.b>>f.c;
    cin>>domain.p;
    cin>>epochs;

    buildDomain();

    srand(time(NULL));
    Generation g(n);

    fout<<"Initial Population:\n";
    g.printPopulation();
    g.printStatus();

    g.selectionWithPrint();
    fout<<"Population after selection:\n";
    g.printPopulation();


    fout<<"\nCrossover probability: "<<CROSSOVER_PROB<<'\n';
    g.genCrossoverWithPrint();

    fout<<"Population after crossover:\n";
    g.printPopulation();

    //mutation

    fout<<"\nMutation probability: "<<MUTATION_PROB<<'\n';
    g.mutationWithPrint();

    fout<<"Population after mutation:\n";
    g.printPopulation();

    fout<<right<<setw(3)<<1<<". ";
    g.printStatus();






    for(int epoch =2; epoch <= epochs;epoch++){
        g.selection();
        g.genCrossover();
        g.mutation();

        fout<<right<<setw(3)<<epoch<<". ";
        g.printStatus();
    }

}



