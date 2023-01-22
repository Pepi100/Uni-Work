#include <bits/stdc++.h>


using namespace std;
ifstream fin("harta.in");
ofstream fout("harta.out");

int flow = 0, n, m;



int matrice[1001][1001], copie[1001][1001], tata[1001], visited[1001], copievis[1001];
queue <int> q;

void dfs( int nod)
{
    copievis[nod] = 1;
    for (int i = 1; i <= n; i++)
        if (matrice[nod][i] && !copievis[i])
            dfs( i);
}

int bfs(){

    for(int i=1;i<=n;i++){
        visited[i] = 0;
        tata[i] = 0;
    }


    queue<int> empty;
    swap( q, empty ); // golim stiva

    //incepem bfs de la nodul 1

    q.push(1);
    visited[1] = 1;

    while(!q.empty()){

        if(q.front() == n){
            return 1;
        }

        int elem = q.front();
        q.pop();

        for(int i=1; i<=n;i++){
            if(visited[i] == 0 && matrice[elem][i]>0 ){
                tata[i]=elem;
                visited[i] = 1;
                q.push(i);

            }
        }



    }
    return 0;


}


int main() {

    fin>>n>>m;
    int a,b;
    for(int i=1;i<=m;i++){
        fin>>a>>b;
        fin>>matrice[a][b];
        copie[a][b] = matrice[a][b];
    }

    int rez = 0;

    while(bfs()){


        for(int i=1;i<=n;i++){

            if(visited[i] && matrice[i][n] > 0) {
                int aux = 2000000000;
                int nod = n;
                tata[n] = i;
                //reconstruim drumul, folosind vectorul de tati si calculam valoarea cu care se poate traversa
                while (tata[nod] > 0) {
                    aux = min(aux, matrice[tata[nod]][nod]);
                    nod = tata[nod];

                }


                //actualizam valorile

                nod = n;

                while (tata[nod] > 0) {
                    matrice[tata[nod]][nod] -= aux;
                    matrice[nod][tata[nod]] += aux;

                    nod = tata[nod];

                }
                rez += aux;

            }


        }



    }
//    cout<<"graf:"<<endl;
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//            cout<< matrice[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    dfs(1);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (copievis[i] && !copievis[j] && copie[i][j])
                cout << i << " -> " << j << endl;

    fout<<rez;


    return 0;
}
