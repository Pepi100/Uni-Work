#include <fstream>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct drum {
	int destinatie = 0;
	char litera = 0;

};

int nrStari, nrTranzitii, stareInitiala, nrFinal, nrCuv;
vector<vector<drum>>muchii;

vector<int>stariFinale;
vector<int>path;
vector<int>pathAfisare;


//aceste mapuri ma ajuta sa pot avea starile numerotate cu orice fel de numere
//asociez fiecarei stari citita din fisier un index, numere consecutive, de la 0
//asociereInversa este necesar doar pentru afisarea drumului
map<int, int> asociere; 
map<int, int> asociereInversa; 

void citireStari(int n) {
	int x;
	for (int i = 0; i < n; i++) {
		fin >> x;
		asociere[x] = i;
		asociereInversa[i] = x;
	}
}

void citireTranzitii(int n) {
	for (int i = 1; i <= n; i++)
	{
		vector<drum>v;
		muchii.push_back(v);
	}

	int x, y;
	char l;
	drum d;
	for (int i = 1; i <= n; i++) {
		fin >> x >> y >> l;

		d.destinatie = y;
		d.litera = l;
		muchii[asociere[x]].push_back(d);
	}

}

void citireFinal(int n) {
	int x;
	for (int i = 1; i <= n; i++) {
		fin >> x;
		stariFinale.push_back(asociere[x]);
	}
}


int verificare(char* cuv, int k, int stare) {
	path.push_back(stare);
	if (k == strlen(cuv)) {
		if (find(stariFinale.begin(), stariFinale.end(), stare) != stariFinale.end()) {
			pathAfisare = path;
			return 1;
		}
		
		else {
			path.pop_back(); 
			return 0;
		}
	}
	else {
		//cautam in vectorul starii actuale
		int posibilitati = 0;


		for (int i = 0; i < muchii[stare].size() && posibilitati == 0; i++) {
			if (muchii[stare][i].litera == cuv[k])
				posibilitati += verificare(cuv, k + 1, asociere[muchii[stare][i].destinatie]);


			if (muchii[stare][i].litera == '&' ) //am presupus ca inputul in cazul cand o muchie are valoarea lambda va fi de forma <stare> <destinatie> &
				posibilitati += verificare(cuv, k, asociere[muchii[stare][i].destinatie]);

			
		}
		path.pop_back();


		//daca nu gasim nimic returnam 0
		return posibilitati;

	}
}

void rezolvare(int n) {

	char cuv[100];

	for (int i = 1; i <= n; i++) {

		//citim cuvantul
		fin >> cuv;
		fin.get();
		int ok;
		path.clear();
		ok = verificare(cuv, 0, asociere[stareInitiala]);

		if (ok >= 1) {
			fout << "DA ";
			for (int i = 0; i < pathAfisare.size(); i++)fout << asociereInversa[pathAfisare[i]] << ' ';
			fout << '\n';
		}
			
		else
			fout << "NU" << "\n";

	}

}



int main()
{
	fin >> nrStari;

	citireStari(nrStari);

	fin >> nrTranzitii;

	citireTranzitii(nrTranzitii);

	fin >> stareInitiala;

	fin >> nrFinal;

	citireFinal(nrFinal);

	fin >> nrCuv;

	rezolvare(nrCuv);






}

