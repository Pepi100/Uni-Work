#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <stdlib.h>


void* strrev (void *v){
    char * word  = (char*) v;
    int length = strlen(word);
    char * result = (char *)malloc((length+1)*sizeof(char));


    // printf("Hello, %s!\n", word);

    int i=0;
    for( i =0; i<length; i++){
        result[i] = word[length-1-i];
    }
    result[i]='\n';

    // printf("Cuvant: %s", result);    


    return result;

}


int main (int argc, char* argv[])
{
    


    if( argc < 2){
        printf("Numar invalid arg.\n");
        return EINVAL;
    }





    void * result;
    pthread_t thr;



    if( pthread_create(&thr, NULL, strrev, argv[1] )  )
    {
        perror("Eroare creare thread");
        return errno;

    }

    if( pthread_join(thr, &result)){

        perror("Eroare finalizare thread");
        return errno;

    }

    char * word  = (char*) result;

    printf("%s\n", word);

 

 

    return 0;




}

// folosim threaduri cand sunt lucruri mai mici de facut
// acestea partajeaza memoria