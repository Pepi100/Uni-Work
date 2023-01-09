#include <bits/stdc++.h>


using namespace std;
ifstream fin("harta.in");
ofstream fout("harta.out");

int flow = 0, n, m;



int matrice[1001][1001], tata[1001], visited[1001];
queue <int> q;

int bfs(int start, int end){

    for(int i=1;i<=end;i++){
        visited[i] = 0;
        tata[i] = 0;
    }


    queue<int> empty;
    swap( q, empty ); // golim stiva

    //incepem bfs de la nodul 1

    q.push(start);
    visited[start] = 1;
    tata[start] = -1;

    while(!q.empty()){

        if(q.front() == end){
            return 1;
        }

        int elem = q.front();
        q.pop();

        for(int i=1; i<=end;i++){
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

    fin>>n;
    int a,b;
    int nr=0;
    int start = 0, end = 2*n+1;
    for(int i=1;i<=n;i++){
        fin>>a>>b;
        nr+=a;
        matrice[start][i] = a;
        matrice[n+i][end] = b;
    }

    fout<<nr<<'\n';

    //legam toate nodurile intre ele

    for(int i=1;i<=n;i++){
        for(int j= n+ 1;j<=2 *n;j++)
            if(j-n != i){
                matrice[i][j] = 1;
            }
    }

    int rez = 0;

    while(bfs(start, end)){


        for(int i=1;i<=n;i++){
            int aux = 2000000000;
            if(visited[n+i] && matrice[n+i][end] > 0) {

                int nod = end;
                tata[nod] = n+i;
                //reconstruim drumul, folosind vectorul de tati si calculam valoarea cu care se poate traversa
                while (nod > 0) {
                    aux = min(aux, matrice[tata[nod]][nod]);
                    nod = tata[nod];

                }
                if(aux == 0) continue;

                //actualizam valorile

                nod = end;

                while (nod > 0) {
                    matrice[tata[nod]][nod] -= aux;
                    matrice[nod][tata[nod]] += aux;

                    nod = tata[nod];

                }


            }


        }



    }


    for(int i = 1; i <= n; i++) {
        for(int j = n+ 1; j <= end-1; j++)
            if( matrice[i][ j] == 0 && i != j-n)
                fout << i << " " << j-n << '\n';

    }



    return 0;
}
