#include <bits/stdc++.h>
#include <ctime>
#include <random>
#define ELITISM true

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

        genes[p] = (genes[p]-'0'+1)%2;
        updateValue();

    }


};

class Generation{
private:
    vector <Chromosome> population ;
    int size;
    int precision;

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

    //crossovers

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





};

double crossover_prob, mutation_prob;
int epochs;


int main() {
    //citire
    int n;
    cin>>n;
    cin>>domain.a>>domain.b;
    cin>>f.a>>f.b>>f.c;
    cin>>domain.p;
    cin>>crossover_prob>>mutation_prob;
    cin>>epochs;

    buildDomain();

    srand(time(NULL));
    Generation g(n);

    fout<<"Initial Population:\n";

    for(int i=0;i<g.getSize();i++){
        fout<<"  "<<right << setw(3)<<i+1<<".  "<<g.getChromosome(i).getGenes()<<"  val="<<right << setw(10)<<fixed<<setprecision(6)<< g.getChromosome(i).getValue()<<"  fitness= "<<right << setw(9)<<g.getChromosome(i).getFitness()<<"\n";
    }

    fout<<"\nSelection Probability: \n";
    double fit = g.getFitness();

    for(int i=0;i<g.getSize();i++){
        fout<<"  chromosome: "<<right << setw(3)<<i+1<<".  probability= "<<right << setw(11)<<g.getChromosome(i).getFitness()/fit<<"\n";
    }

    fout<<"\nSelection Probability Intervals: \n";
    double aux[g.getSize()+1];
    aux[0]=0;
    fout<<aux[0]<<" ";
    for(int i=0;i<g.getSize()-1;i++){
        aux[i+1]=aux[i]+ g.getChromosome(i).getFitness()/fit;
        fout<<aux[i+1]<<" ";
    }
    aux[g.getSize()] = 1;
    fout<<aux[g.getSize()]<<'\n';

    //selectarea cromozomilor
    vector <Chromosome> popl;
        //criteriul elitist;

        if(ELITISM){
            popl.push_back(g.getBest());

            fout<<"The best choromose was automatically selected for crossover!\n";
        }

        while(popl.size() < g.getSize()){
            //generate random u;
            double u= rand() / (double) RAND_MAX;

            int left = 0, right = g.getSize();

            while(right-left >1){
                int mid = (right+ left)/2;

                if(u<aux[mid]){
                    right = mid;
                }else{
                    left=mid;
                }

            }

            fout<<"  u=" << setw(11)<<u<<"  selecting chromosome "<< setw(3)<<left+1<<'\n';
            popl.push_back(g.getChromosome(left));

        }

    fout<<"Population after selection:\n";
    for(int i=0;i<g.getSize();i++){
        fout<<"  "<<right << setw(3)<<i+1<<".  "<<popl[i].getGenes()<<"  val="<<right << setw(10)<<fixed<<setprecision(6)<< popl[i].getValue()<<"  fitness= "<<right << setw(9)<<popl[i].getFitness()<<"\n";
    }
    g.setPopulation(popl);


    fout<<"\nCrossover probability: "<<crossover_prob<<'\n';
    queue <int> cross_selection;

    for(int i=0;i<g.getSize();i++){
        double u= rand() / (double) RAND_MAX;

        fout<<"  "<<right << setw(3)<<i+1<<".  "<<popl[i].getGenes()<<"  val="<<right << setw(10)<<fixed<<setprecision(6)<< popl[i].getValue()<<"  u= "<<right << setw(9)<<u;
        if(u<crossover_prob){
            fout<< " < "<<crossover_prob<<" SELECTED\n";
            cross_selection.push(i);
        }

        else fout<<'\n';
    }

    while(cross_selection.size() != 3 && !cross_selection.empty()){
        int a = cross_selection.front();
        cross_selection.pop();

        int b = cross_selection.front();
        cross_selection.pop();

        int i= 1+rand()%(domain.l/2);
        fout<<setw(3)<<"Crossover between " << a+1<< " and "<<b+1<< " with crossover point "<<i+1<<"\n  Before:\n   ";

        for(int j=0;j<domain.l;j++){
            fout<<g.getChromosome(a).getGenes()[j];
            if(j==i){
                fout<<'|';
            }
        }
        fout<<"\n   ";

        for(int j=0;j<domain.l;j++){
            fout<<g.getChromosome(b).getGenes()[j];
            if(j==i){
                fout<<'|';
            }
        }

        g.crossover(a,b,i);

        fout<<"\n  After:\n   ";

        for(int j=0;j<domain.l;j++){
            fout<<g.getChromosome(a).getGenes()[j];
            if(j==i){
                fout<<'|';
            }
        }
        fout<<"\n   ";

        for(int j=0;j<domain.l;j++){
            fout<<g.getChromosome(b).getGenes()[j];
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
            fout<<g.getChromosome(a).getGenes()[j];
            if(j==i){
                fout<<'|';
            }
        }
        fout<<"\n   ";

        for(int j=0;j<domain.l;j++){
            fout<<g.getChromosome(b).getGenes()[j];
            if(j==i){
                fout<<'|';
            }
        }

        fout<<"\n   ";

        for(int j=0;j<domain.l;j++){
            fout<<g.getChromosome(c).getGenes()[j];
            if(j==i){
                fout<<'|';
            }
        }

        g.crossover(a,b,c,i);

        fout<<"\n  After:\n   ";

        for(int j=0;j<domain.l;j++){
            fout<<g.getChromosome(a).getGenes()[j];
            if(j==i){
                fout<<'|';
            }
        }
        fout<<"\n   ";

        for(int j=0;j<domain.l;j++){
            fout<<g.getChromosome(b).getGenes()[j];
            if(j==i){
                fout<<'|';
            }
        }
        fout<<"\n   ";
        for(int j=0;j<domain.l;j++){
            fout<<g.getChromosome(c).getGenes()[j];
            if(j==i){
                fout<<'|';
            }
        }
        fout<<"\n";
    }


    //mutation

    fout<<"\nMutation probability: "<<mutation_prob<<'\n';

    //rare mutation
    for(int i=0;i<g.getSize();i++){
        double u= rand() / (double) RAND_MAX;

        fout<<"  "<<right << setw(3)<<i+1<<".  "<<g.getChromosome(i).getGenes()<<"  val="<<right << setw(10)<<fixed<<setprecision(6)<< g.getChromosome(i).getValue()<<"  u= "<<right << setw(9)<<u;
        if(u<mutation_prob){
            fout<< " < "<<mutation_prob<<" SELECTED\n";
            g.getChromosome(i).rareMutation();
        }
        else fout<<'\n';
    }








    for(int epoch =1; epoch < epochs;epoch++){



    }

}



