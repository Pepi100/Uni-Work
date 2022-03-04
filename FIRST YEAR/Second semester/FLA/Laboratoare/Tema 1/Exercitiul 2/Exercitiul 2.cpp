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


map<int, int> asociere;

void citireStari(int n) {
	int x;
	for (int i = 0; i < n; i++) {
		fin >> x;
		asociere[x] = i;
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
	if (k == strlen(cuv)) {
		if (find(stariFinale.begin(), stariFinale.end(), stare) != stariFinale.end())
			return 1;
		else return 0;
	}
	else {
		//cautam in vectorul starii actuale
		int posibilitati = 0;

		for (int i = 0; i < muchii[stare].size(); i++) {
			if (muchii[stare][i].litera == cuv[k])
				posibilitati += verificare(cuv, k + 1, asociere[muchii[stare][i].destinatie]);
		}

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
		ok = verificare(cuv, 0, asociere[stareInitiala]);

		if (ok >= 1)
			fout << "DA" << "\n";
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

