#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main(){

    char  shm_name[] = "myshm";
    int shm_fd = shm_open(shm_name, O_CREAT|O_RDWR , S_IRUSR|S_IWUSR);


    //verificam ca a mers open
    if(shm_fd < 0){
        perror(NULL);
        return errno;
    }

    int shm_size = 500;

    if(ftruncate(shm_fd, shm_size) == -1){
        perror(NULL);

        shm_unlink(shm_name);
        return errno;
    }

    
    pid_t pid = fork();

    if(pid<0){

        perror("eroare creare copil");
        return errno;
    }

    if (pid == 0){
        //scrie in shared memory
        void * shr_ptr = mmap(0,100, PROT_WRITE, MAP_SHARED, shm_fd, 0 );
        //putem sa mapam pentru fiecare copil

        if(shr_ptr == MAP_FAILED){
            perror("Mapping error");
        }

        int *shm_int = (int*)shr_ptr;

        shm_int[0]=10;

        munmap(shr_ptr, 100);



    }else{

        wait(NULL);
        //parintele citeste din shared memory


        void * shr_ptr = mmap(0,500, PROT_READ, MAP_SHARED, shm_fd, 0 );

        if(shr_ptr == MAP_FAILED){
            perror("Mapping error");
        }

        int *shm_int = (int*) shr_ptr;

        printf("x= %d\n", shm_int[0]);

        munmap(shr_ptr, 500);
        shm_unlink(shm_name);

    }





}