#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RESOURCES 10
#define nr_threads 10
int available_resources=MAX_RESOURCES;


pthread_mutex_t mtx;
int decrease_count (int count)
{
    if (pthread_mutex_lock(&mtx))
    {
        printf("Eroare la scaderea numarului de resurse\n");
    }

    // dam resurse doar daca avem de unde
    if (count <= available_resources)
    {
        available_resources -= count;
        printf("Got %d resources, %d remaining\n", count, available_resources);
    }
    return pthread_mutex_unlock(&mtx);
}
int increase_count(int count)
{
    if (pthread_mutex_lock(&mtx))
    {
        printf("Eroare la cresterea numarului de resurse\n");
    }

    // numarul de resurse nu trebuie sa depaseasca numarul maxim
    if (available_resources + count <= MAX_RESOURCES)
    {
         available_resources += count;
         printf("Released %d resources, %d remaining\n", count, available_resources);
    }

    return pthread_mutex_unlock(&mtx);
}
void * threadStart (void *v)
{
    int nr=*((int *)v);
    decrease_count(nr);
    increase_count(nr);
    return NULL;
}

int main()
{
    pthread_t thr[nr_threads];
    printf("MAX_RESOURCES=%d\n", MAX_RESOURCES);
    

    if(pthread_mutex_init(&mtx, NULL))
    {
        perror(NULL);
        return errno;

    }
 
 
    //creez cele n thread-uri
    for(int i=0; i<nr_threads; i++)
    {
        int *nr_res=(int*)malloc(sizeof(int));
        (*nr_res)=rand()%(MAX_RESOURCES/2+1)+1;
        //fiecare thread va avea nevoie de un numar aleator de resurse
        if(pthread_create(&thr[i], NULL, threadStart, nr_res))
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

    //distrugere mutex la final
    pthread_mutex_destroy(&mtx);
    return 0;
}