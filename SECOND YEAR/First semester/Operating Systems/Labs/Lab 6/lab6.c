#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <stdlib.h>

int x;
void* hello (void *v){
    char * who  = (char*) v;
    printf("Hello, %s!\n", who);
    return NULL;

}


int main (int argc, char* argv[])
{
    x=0;

    if( argc < 3){
        printf("Numar invalid arg.\n");
        return EINVAL;
    }



    int nr_threads = strtol(argv[1], NULL, 10);

    printf("Voi crea %d fire de executie.\n", nr_threads);


    //array de threaduri
    pthread_t *thr = (pthread_t*) malloc (nr_threads*sizeof(pthread_t));

    for(int i=0; i< nr_threads; i++){
        

        if( pthread_create(thr + i, NULL, hello, argv[2+i] )  )
        {
            perror("Eroare creare thread");
            return errno;

        }

    }

    void * result;


    //astept finalul executiei pentru fiecare dintre threadurile create
    for(int i=0; i< nr_threads; i++)
    if( pthread_join(thr[i], &result)){

        perror("Eroare finalizare thread");
        return errno;

    }

    free(thr);

    printf("x= %d", x);

    return 0;




}

// folosim threaduri cand sunt lucruri mai mici de facut
// acestea partajeaza memoria