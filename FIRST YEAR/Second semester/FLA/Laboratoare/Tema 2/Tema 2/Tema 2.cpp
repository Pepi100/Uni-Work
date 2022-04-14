
#include <algorithm>
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <set>



using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

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

	int getDestinatie() {
		return destinatie;
	}

	char getLitera() {
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
	vector <int> stari;
	vector <int> stariFinale;
	vector<vector<Salt>>muchii;

public:

	Automat() {
		vector<int> vect;
		nrStari = 0;
		stareInitiala = 0;
		nrStariFinale = 0;
		stari = vect;
		stariFinale = vect;
	}

	Automat(int _nrStari, vector <int> _stari, int _stareInitiala, int _nrStariFinale, vector <int> _stariFinale) {
		nrStari = _nrStari;
		stari = _stari;
		stareInitiala = _stareInitiala;
		nrStariFinale = _nrStariFinale;
		stariFinale = _stariFinale;
	}

	int getStareInitiala() {
		return stareInitiala;
	}

	int getNrStari() {
		return nrStari;
	}

	vector<int> getStari() {
		return stari;
	}

	int getNrStariFinale() {
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

	void setStari(vector<int> v) {
		stari = v;
	}

	void setNrStariFinale(int x) {
		nrStariFinale = x;
	}

	void setStariFinale(vector<int> v) {
		stariFinale = v;
	}

	void setMuchii(vector<vector<Salt>> _muchii) {
		muchii= _muchii;
	}

	vector<vector<Salt>> getMuchii() {
		return muchii;
	}

	void citireFisier() {
		int aux, x;//ajutor pentru citire
		char c;
		int maxim = 0;
		fin >> nrStari;
		
		for (int i = 1; i <= nrStari; i++)
		{
			fin >> x;
			stari.push_back(x);

			maxim = max(maxim, x);
		}
			
		int nrTranzitii;
		fin >> nrTranzitii;
		

		for (int i = 1; i <= maxim+1; i++)
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
			
			
				
			for (int i = 0; i < muchii[stareActuala].size(); i++) {
				
				if (muchii[stareActuala][i].getLitera() == cuv[k])
				{
					
					posibilitati += verificareCuvant(cuv, k + 1, muchii[stareActuala][i].getDestinatie());
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

		int maxim = 0;
		for (int i = 0; i < nrStari; i++)
		{
			maxim = max(maxim, stari[i]);
		}

		stari.push_back(maxim + 1);

	}

	void setStareFinala(int _stare) {
		
		stariFinale.push_back(_stare);
		
		nrStariFinale++;

	}

};







class DFA : public Automat {
private:
	int deadState = 0;


public:
	DFA() {
		vector<int> vect;
		setNrStari(0);
		setStari(vect);
		setStareInitiala(0);
		setNrStariFinale(0);
		setStariFinale(vect);
		deadState = 0;

	}

	DFA(int _nrStari, vector <int> _stari, int _stareInitiala, int _nrStariFinale, vector <int> _stariFinale, int _deadState) {
		setNrStari(_nrStari);
		setStari(_stari);
		setStareInitiala(_stareInitiala);
		setNrStariFinale(_nrStariFinale);
		setStariFinale(_stariFinale);


		deadState = _deadState;
	
	}


	int getDeadState() {
		return deadState;
	}

	void setDeadState(int _deadState) {
		deadState = _deadState;
	}

	DFA toMinimal() {
		
		

		
			

		

		

	}


	

};


class NFA : public Automat {
private:

public:

	DFA toDFA(){
		
		int maxim = 0;
		for (int i = 0; i < getNrStari(); i++)
		{	
			maxim = max(maxim, getStari()[i]);
		}

		int _deadstate = maxim + 1;
	

		DFA d( getNrStari(), getStari(), getStareInitiala() ,getNrStariFinale(), getStariFinale(), _deadstate);
		
		
		vector <int> v = getStari();
		v.push_back(_deadstate);
		d.setStari(v);
		d.setNrStari(1 + d.getNrStari());
		d.setMuchii(getMuchii());

		
		vector <char> litere;
		for (int i = 0; i < d.getMuchii().size(); i++) {

			for (int j = 0; j < d.getMuchii()[i].size(); j++) {
				if (count(litere.begin(), litere.end(), d.getMuchii()[i][j].getLitera()) == 0) litere.push_back(d.getMuchii()[i][j].getLitera());
			}
		}
		for (int i = 0; i < d.getStari().size(); i++) {
			//verificam pentru fiecare stare daca are muchie cu toate literele din litere, daca nu, adaugam o muchie de la ea la deadstate cu muchia lipsa
			for (int l = 0; l < litere.size(); l++) {
				int ok = 0;
				for (int j = 0; j < d.getMuchii()[i].size(); j++) {
					if (d.getMuchii()[i][j].getLitera() == litere[l])
						ok = 1;
				}
				if (ok == 0) {
					Salt s;
					s.setDestinatie(d.getDeadState() );
					s.setLitera(litere[l]);
					d.getMuchii()[i].push_back(s);
				}
			}

		}


		//parcurgerea si adaugarea de muchii

		return d;
	}


};





int main()
{
	NFA a;
	a.citireFisier();

	DFA d;

	

	d = a.toDFA();
	char cuv[100];
	cin >> cuv;
	cout<< d.verificareCuvant(cuv);

	
}


// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
