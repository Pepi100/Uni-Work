
#include <algorithm>
#include <iostream>
#include <cstring>
#include <fstream>
#include <utility>
#include <vector>
#include <map>
#include <set>



using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");



set<int> setDiference( set<int> A, set<int> B  ){
    for(auto value: B){
        A.erase(value);
    }

    return A;
}


set<int> setUnion (set<int> A, set<int> B){
    for(auto value: A){
        if(B.count(value) == 0) A.erase(value);
    }

    return A;

}


class Salt {
private:
    int destinatie = 0;
    char litera = 0;
public:
    Salt(){}


    Salt(int _d, char _l){
        destinatie = _d;
        litera = _l;
    }

    int getDestinatie() const {
        return destinatie;
    }

    char getLitera() const {
        return litera;
    }


    void setDestinatie(int _d) {
        destinatie = _d;
    }

    void setLitera(char _l) {
        litera = _l;
    }



};


class Automat {
protected:
    int nrStari;
    int stareInitiala;
    int nrStariFinale;
    vector <int> stariFinale;
    vector<vector<Salt>>muchii;
    vector<char> alfabet;

public:

    Automat() {
        vector<int> vect;
        nrStari = 0;
        stareInitiala = 0;
        nrStariFinale = 0;
        stariFinale = vect;
    }

    Automat(int _nrStari, int _stareInitiala, int _nrStariFinale, vector <int> _stariFinale) {
        nrStari = _nrStari;
        stareInitiala = _stareInitiala;
        nrStariFinale = _nrStariFinale;
        stariFinale = move(_stariFinale);
    }

    int getStareInitiala() const{
        return stareInitiala;
    }

    int getNrStari() const{
        return nrStari;
    }

    const vector<char> &getAlfabet() const {
        return alfabet;
    }

    int getNrStariFinale() const{
        return nrStariFinale;
    }

    vector <int> getStariFinale() {
        return stariFinale;
    }



    void setStareInitiala(int x) {
        stareInitiala = x;
    }

    void setNrStari(int x) {
        nrStari = x;
    }


    void setNrStariFinale(int x) {
        nrStariFinale = x;
    }

    void setStariFinale(vector<int> v) {
        stariFinale = move(v);
    }

    void setMuchii(vector<vector<Salt>> _muchii) {
        muchii= move(_muchii);
    }

    vector<vector<Salt>> getMuchii() {
        return muchii;
    }

    void citireFisier() {
        int aux, x;//ajutor pentru citire
        char c;
        fin >> nrStari;




        int nrTranzitii;
        fin >> nrTranzitii;


        for (int i = 1; i <= nrStari+1; i++)
        {
            vector<Salt>v;
            muchii.push_back(v);
        }

        for (int i = 1; i <= nrTranzitii; i++) {
            fin >> aux;
            fin >> x >> c;
            Salt s;
            s.setDestinatie(x);
            s.setLitera(c);
            muchii[aux].push_back(s);

            int ok =0;
            for(auto chr :alfabet){
                if(chr == c) ok =1;
            }
            if(ok==0) alfabet.push_back(c);

        }

        fin >> stareInitiala;
        fin >> nrStariFinale;
        for (int i = 1; i <= nrStariFinale; i++) {
            fin >> x;
            stariFinale.push_back(x);
        }
    }


    int verificareCuvant(char *cuv) {
        return verificareCuvant(cuv, 0, stareInitiala);
    }

    int verificareCuvant(char* cuv, int k, int stareActuala) {


        if (k == strlen(cuv)) {

            if (find(stariFinale.begin(), stariFinale.end(), stareActuala) != stariFinale.end())
                return 1;
            else return 0;
        }
        else {
            //cautam in vectorul starii actuale
            int posibilitati = 0;



            for (auto & i : muchii[stareActuala]) {

                if (i.getLitera() == cuv[k])
                {

                    posibilitati += verificareCuvant(cuv, k + 1, i.getDestinatie());
                }
            }

            //daca nu gasim nimic returnam 0
            return !(!posibilitati);

        }
    }


    void addStare() {
        vector<Salt> v;
        muchii.push_back(v);
        nrStari++;


    }

    void setStareFinala(int _stare) {

        stariFinale.push_back(_stare);

        nrStariFinale++;

    }

    bool isFinal(int _stare){
        for(auto itr: stariFinale)
            if(itr == _stare) return true;
        return false;
    }

    void addSalt(int _start, int _destinatie, char _litera){

        Salt s(_destinatie, _litera);

        vector<Salt>v;
        muchii.push_back(v);
        muchii[_start].push_back(s);

    }

    friend ofstream& operator << (ofstream& os, const Automat& a){
        os << "Numar stari: " << a.nrStari << "\n";
        os << "Salturi:\n";
        for (int i = 0; i < a.nrStari; i++)
            for (int j = 0; j < a.muchii[i].size(); j++)
                os << i << " " << a.muchii[i][j].getDestinatie() << " " << a.muchii[i][j].getLitera() << "\n";
        os << "Stare initiala: " << a.stareInitiala << "\nStarile finale: ";
        for (int i = 0; i < a.nrStariFinale; i++)
            os << a.stariFinale[i] << " ";
        os << "\n";
        return os;
    }



};




class DFA : public Automat {
private:
    int deadState = 0;


public:
    DFA() {
        vector<int> vect;
        setNrStari(0);

        setStareInitiala(0);
        setNrStariFinale(0);
        setStariFinale(vect);
        deadState = 0;

    }

    DFA(int _nrStari, int _stareInitiala, int _nrStariFinale, vector <int> _stariFinale, int _deadState) {
        setNrStari(_nrStari);
        setStareInitiala(_stareInitiala);
        setNrStariFinale(_nrStariFinale);
        setStariFinale(move(_stariFinale));


        deadState = _deadState;

    }


    int getDeadState() const {
        return deadState;
    }

    void setDeadState(int _deadState) {
        deadState = _deadState;
    }

    DFA toMinimal() const{
        //eliminarea starilor la care nu se poate ajunge

        set<int> reachable_states= {stareInitiala,};
        set<int> new_states= {stareInitiala,};

        do{
            set<int> temp;
            for(auto stare: new_states){ //pentru fiecare stare din setul actual trec adaug in temp toate starile la care se poate ajunge de acolo
                for(auto salt: muchii[stare]){
                    new_states.insert(salt.getDestinatie());
                }
            }

            for(auto stare:reachable_states) //new_states := temp \ reachable_states
                new_states.erase(stare);

            for(auto stare: new_states)   // reachable_states := reachable_states ∪ new_states
                reachable_states.insert(stare);




        }while(!new_states.empty());

        set<int> unreachable_states;
        for(int i=0;i<nrStari;i++)
            if(reachable_states.count(i) == 0)
                unreachable_states.insert(i);

        //acum scoatem starile la care nu se poate ajunge



        //algoritmul lui Hopcroft -> partition refinement
        set< set<int> > P ;
        set<int> finale, nefinale;
        for(auto stare: reachable_states){
            if(count(stariFinale.begin(), stariFinale.end(), stare) ==  1)
                finale.insert(stare);
            else nefinale.insert(stare);
        }
        P.insert(finale);
        P.insert(nefinale);

        set< set<int> > W  = P;

        //while W is not empty do
        while(!W.empty()){
            //choose and remove a set A from W
            set<int>A = *W.begin();
            W.erase(W.begin());


                for(auto litera: alfabet){//for each c in the alphabet do
                    set<int> X; //let X be the set of states for which a transition on c leads to a state in A
                    for(auto stare: reachable_states){
                        for(auto salt:muchii[stare]){
                            if(salt.getLitera() == litera && A.count(salt.getDestinatie()) == 1) X.insert(stare);
                        }

                    }

                    for(auto Y:P){
                        if(!setDiference(Y, X).empty() && !setUnion(X, Y).empty()){
                            P.erase(Y);
                            P.insert(setDiference(Y, X));
                            P.insert(setUnion(X, Y));

                            if(W.count(Y) == 1){
                                W.erase(Y);
                                W.insert(setDiference(Y, X));
                                W.insert(setUnion(X, Y));
                            }else{
                                if( setUnion(X, Y).size()  <=  setDiference(Y, X).size()){
                                    W.insert(setUnion(X, Y));
                                }else{
                                    W.insert(setDiference(Y, X));
                                }

                            }
                        }
                    }



            }

        }
        DFA result;
        vector <vector<Salt>>m;
        std::map<int, int> partitions;
        int partition_index = 0;
        for (const auto &s: P) {
            for (int x: s) {
                partitions[x] = partition_index;
            }
            partition_index++;
            result.addStare();


        }



        partition_index = 0;

        for (const auto &s: P) {
            for (int x: s) {
                //Daca starea a fost initial una finala, atuci si partitia din care va face parte va fi tot una finala
                if (find(stariFinale.begin(), stariFinale.end(), x) != stariFinale.end() ) {
                    result.setStareFinala(partition_index);
                }

                //Similar pentru starile initiale.
                if (x == stareInitiala) {
                    result.setStareInitiala( partition_index);
                }



                //For each edge from this state, add edges to the partition containing the neighbouring state.
                    for(auto s:muchii[x]){
                        if(reachable_states.count(x) == 1) //Only consider states that are valid
                             result.addSalt(partition_index, partitions[s.getDestinatie()], s.getLitera());
                    }




            }
            partition_index++;
        }

        return result;

    }




};







class NFA : public Automat {
private:

public:

    DFA toDFA(){



        map<set<int>, int> nr_multime;
        vector<set<int>> coada;

        DFA d;
        d.setNrStari(1);
        d.setStareInitiala(0);
        coada.push_back( {stareInitiala, } );
        coada[0] = {stareInitiala, };
        nr_multime[{stareInitiala,}]=0;




        for (int i = 0; i < d.getNrStari(); i++) //parcurgem coada cu starile noului automat
        {

            for (auto litera : alfabet)//pentru fiecare stare ma uit la fiecare posibila litera si alcatuiesc setul actual
            {


                set<int> setActual;

                for (auto itr : coada[i])
                    //alcatuiesc setul actual parcurgand toate muchiile care pot iesi cu litera curenta din setul de stari la care am ajuns in coada
                    for (auto s : muchii[itr])
                        if (s.getLitera() == litera) setActual.insert(s.getDestinatie());

                if (nr_multime.find(setActual) == nr_multime.end()) //daca setul actual format nu se afla deja in multimea de stari o adaugam.
                {

                    d.addStare();
                    nr_multime[setActual] = d.getNrStari() - 1;
                    coada.push_back(setActual);


                    //daca vreuna din starile din setul actual este finala, atunci noua stare formata va fi una finala
                    for (auto x : setActual)
                        if (isFinal(x))
                        {
                            d.setStareFinala(d.getNrStari() - 1);
                        }
                }


                d.addSalt(i, nr_multime[setActual], litera);

            }
        }





        return d;
    }


};





int main()
{
    DFA d;
    d.citireFisier();
    fout<<d;
    fout<<endl<<endl;
    d=d.toMinimal();
    fout<<d;





}


// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
