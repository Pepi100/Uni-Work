#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

struct tranz
{
    int y, l;
};

class Automat {
protected:
    int n, m, s, nrF;
    vector<vector<tranz>> muchii;
    vector <int> starif;
    set<int> litere;
public:
    Automat() {
        n = m = nrF = 0;
    }

    void adauga_stare(int i) {
        vector<tranz> v;
        muchii.push_back(v);
        n++;
    }

    void adauga_muchie(int x, int y, int l) {
        m++;
        tranz t;
        t.y = y; t.l = l;
        muchii[x].push_back(t);
    }

    void adauga_finala(int i) {
        nrF++;
        starif.push_back(i);
    }

    bool stare_finala(int i) {
        for (auto itr : starif)
            if (itr == i) return 1;
        return 0;
    }

    friend ifstream& operator >> (ifstream& in, Automat& a)
    {
        in >> a.n;
        vector <tranz> v;
        for (int i = 0; i < a.n; i++)
            a.muchii.push_back(v);
        in >> a.m;
        int x;
        tranz t;
        for (int i = 0; i < a.m; i++)
            in >> x >> t.y >> t.l, a.muchii[x].push_back(t), a.litere.insert(t.l);
        in >> a.s >> a.nrF;
        for (int i = 0; i < a.nrF; i++)
            in >> x, a.starif.push_back(x);
        return in;
    }
    friend ofstream& operator << (ofstream& os, const Automat& a)
    {
        os << "Nr stari: " << a.n << "\n";
        os << "Tranzitiile:\n";
        for (int i = 0; i < a.n; i++)
            for (int j = 0; j < a.muchii[i].size(); j++)
                os << i << " " << a.muchii[i][j].y << " " << a.muchii[i][j].l << "\n";
        os << "Stare initiala: " << a.s << "\nStarile finale: ";
        for (int i = 0; i < a.nrF; i++)
            os << a.starif[i] << " ";
        os << "\n";
        return os;
    }

    int getN() const {
        return n;
    }

};


class DFA : public Automat {
public:

};

class NFA : public Automat {
public:
    DFA transf_dfa() {
        map <set<int>, int> multime_stare;
        vector <set<int>> stare_multime;
        DFA d;
        set<int> multime;
        multime.insert(this->s);
        multime_stare[multime] = 0;
        stare_multime.push_back(multime);
        d.adauga_stare(0);

        if (this->stare_finala(this->s)) d.adauga_finala(this->s);

        for (int i = 0; i < d.getN(); i++)
        {
            for (auto litera : this->litere)
            {
                multime.clear();
                for (auto itr : stare_multime[i])
                    for (auto t : this->muchii[itr])
                        if (t.l == litera) multime.insert(t.y);

                if (multime_stare.find(multime) == multime_stare.end())
                {
                    d.adauga_stare(d.getN());
                    multime_stare[multime] = d.getN() - 1;
                    stare_multime.push_back(multime);

                    for (auto x : multime)
                        if (this->stare_finala(x))
                        {
                            d.adauga_finala(d.getN() - 1);
                            break;
                        }
                }

                d.adauga_muchie(i, multime_stare[multime], litera);
            }
        }

        return d;
    }

};

int main()
{
    NFA a;
    fin >> a;
    fout << a.transf_dfa();
}