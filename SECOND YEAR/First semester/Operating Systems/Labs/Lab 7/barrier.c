#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <semaphore.h>
#define nr_threads 10



pthread_mutex_t mtx;
sem_t sem ;

int n=0;

void barrier_point(){

    pthread_mutex_lock(&mtx);
    n++;
    // printf ("n= %d  \n " , n );
    if(n == nr_threads){
        printf ("--------Bariera--------  \n " );
        pthread_mutex_unlock(&mtx);
        for(int i = 1; i<=nr_threads;i++){
            sem_post (&sem );
        }

    }else{
        pthread_mutex_unlock(&mtx);
        sem_wait (&sem );
         

    }

   
    
}

void * tfun ( void *     v )
{
    int * tid = ( int *) v ;
    printf ("%d reached the barrier \n " , * tid );
    barrier_point ();
    printf ("%d passed the barrier \n " , * tid );
    free ( tid );
    return NULL ;
}




int main()
{
    pthread_t thr[nr_threads];
    printf("nr_threads=%d\n", nr_threads);
    

    if(pthread_mutex_init(&mtx, NULL))
    {
        perror(NULL);
        return errno;

    }

    if ( sem_init (&sem , 0 , 0 )) {
        perror(NULL);
        return errno;
    }
 
 
    //creez cele n thread-uri
    for(int i=0; i<nr_threads; i++)
    {
        int *nr_thr=(int*)malloc(sizeof(int));
        (*nr_thr) = i;
        if(pthread_create(&thr[i], NULL, tfun, nr_thr))
        {
            perror(NULL);
            return errno;
        }
    }

    //dau join celor n
    for(int i=0; i<nr_threads; i++)
    {
        if(pthread_join(thr[i], NULL))
        {
            perror(NULL);
            return errno;
        }
    }

    //distrugere mutex si semafor la final
    pthread_mutex_destroy(&mtx);
    sem_destroy (&sem );
    return 0;
}