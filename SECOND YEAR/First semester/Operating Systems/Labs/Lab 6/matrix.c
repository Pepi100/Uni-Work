#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <stdlib.h>


int A[200][200], B[200][200], C[200][200], n1,m1,n2,m2;

void* multiply (void *v){
    int * indici  = (int*) v;
    int i= indici[0];
    int j= indici[1];
    // printf("i= %d, j= %d!\n",i,j );

    //efectuam multiplicarea
    for(int k = 0; k<m1;k++){
        C[i][j] += A[i][k]*B[k][j];
    }


    return NULL;

}


int main ()
{

//citim matricele
printf("Introduceti numarul de linii al primei matrici: " );
scanf("%d", &n1);
printf("Introduceti numarul de coloane al primei matrici: " );
scanf("%d", &m1);

printf("Introduceti elementele primei matrici:\n" );


int y;
for(int i=0;i<n1;i++){

    for(int j=0; j<m1; j++){
        scanf("%d", &y);
        A[i][j] = y;
    }
}

printf("Introduceti numarul de linii al celeilalte matrici: " );
scanf("%d", &n2);
printf("Introduceti numarul de coloane al celeilalte matrici: " );
scanf("%d", &m2);

printf("Introduceti elementele celeilalte matrici:\n" );


for(int i=0;i<n2;i++){

    for(int j=0; j<m2; j++){
        scanf("%d", &y);
        B[i][j] = y;
    }
}


if(m1 != n2){

    printf("Cele doua matrici nu sunt compatibile pentru a fi inmultite.");
    return 0;
}


//apelam functie pentru fiecare dintre elementele matricei in care vrem rezultatul
//Aceasta va fi o matrice de marime n1 * m2, deci vom avea nevoie de tot atatea threaduri

int nr_threads = n1*m2;
pthread_t *thr = (pthread_t*) malloc (nr_threads*sizeof(pthread_t));

for(int i=0; i<n1; i++){
    for(int j=0; j<m2; j++){

        //cautam un mod de a trimite ca parametru pe i si j catre functia multiply

        int *arg = malloc(sizeof(int)*3);
        arg[0] = i;
        arg[1] = j;

        if( pthread_create(thr + (i*m2) +j, NULL, multiply, arg)  )
        {
            perror("Eroare creare thread");
            return errno;

        }


    }

}


//asteptam si ca threadurile sa se termine

for(int i=0; i<n1; i++){
    for(int j=0;  j<m2; j++){

        if( pthread_join(thr[ i *m2 + j], NULL)){

            perror("Eroare finalizare thread");
            return errno;

        }

    }
}


    //afisam matricea rezultata:


printf("Matricea rezultata arata astfel:\n");

for(int i=0; i<n1; i++){
    for(int j=0;  j<m2; j++){
        printf("%d ", C[i][j]);
    }

    printf("\n");

}




}






// folosim threaduri cand sunt lucruri mai mici de facut
// acestea partajeaza memoria