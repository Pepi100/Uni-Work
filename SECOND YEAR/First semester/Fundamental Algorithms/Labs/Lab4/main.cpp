#include <bits/stdc++.h>

using namespace std;

ifstream fin("harta.in");
ofstream fout("harta.out");

const int N_MAX = 105;

int N;
pair<int, int> v[N_MAX], used[N_MAX];

vector<int> G[N_MAX];
int Ans;

int main()
{
    fin >> N;
    for (int i = 1; i <= N; i++) {
        fin >> v[i].first >> v[i].second;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = N; j >= 1; j--) {
            if (i != j && v[i].first - used[i].first && v[j].second - used[j].first) {
                used[i].first++;
                used[j].second++;
                G[i].push_back(j);
                Ans++;
            }
        }
    }
    fout << Ans << "\n";
    for (int i = 1; i <= N; i++) {
        //cout << v[i].first << " " << v[i].second << "\n";
        for (int j = 0; j < G[i].size(); j++) {
            fout << i << " " << G[i][j] << "\n";
        }
    }
    return 0;
}
