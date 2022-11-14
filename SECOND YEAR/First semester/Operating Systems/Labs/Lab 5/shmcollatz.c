#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){


    if(argc <2){
        printf("Numar invalid de argumente.\n");
        return EINVAL;
    }

    int mem_size = 4096;

    char shm_name[] = "myshm";
    int shm_fd = shm_open(shm_name, O_CREAT|O_RDWR , S_IRUSR|S_IWUSR);


    //verificam ca a mers open
    if(shm_fd < 0){
        perror(NULL);
        return errno;
    }


    int p =  getpagesize();
    printf("pagesize = %d\n", p);


    int shm_size = mem_size * 10;

    if(ftruncate(shm_fd, shm_size) == -1){
        perror(NULL);

        shm_unlink(shm_name);
        return errno;
    }

    pid_t parent_pid = getpid();

    for(int a=0;a<argc-1;){
    pid_t pid = fork();

    int nr = atoi(argv[a+1]);

        if(pid<0){

            perror("eroare creare copil");
            return errno;
        }

        if (pid == 0){

            //scrie in shared memory
            void * shr_ptr = mmap(0, mem_size, PROT_WRITE, MAP_SHARED, shm_fd, (a*mem_size));
            //putem sa mapam pentru fiecare copil

            if(shr_ptr == MAP_FAILED){
                perror(NULL);
                shm_unlink(shm_name);
                return errno;
            }

            int *shm_int = (int*)shr_ptr;


            

            
            int index = 0;
            shm_int[index]=nr;

            while(nr!=1){
				shm_int[++index]=nr;
				if(nr%2==0) nr/=2;
				else nr=3*nr+1;
			}

			shm_int[++index]=nr;

            munmap(shr_ptr, mem_size);
            break;


        }else{

            wait(NULL);
            printf("Copilul cu id %d a terminat. Parinte: %d\n",pid, getpid());

            //parintele citeste din shared memory



            // void * shr_ptr = mmap(0,shm_size, PROT_READ, MAP_SHARED, shm_fd, 0 );

            // if(shr_ptr == MAP_FAILED){
            //     perror("Mapping error");
            // }

            // int *shm_int = (int*) shr_ptr;

         

            // munmap(shr_ptr, 500);
            // shm_unlink(shm_name);
            a++;

        }

    }

    //acum parintele isi face treaba si combina rezultatele tuturor copiilor

    if(getpid() == parent_pid) {
        //pentru fiecare copil ne uitam in bucata lui de memorie si afisam
        for(int a=0; a< argc-1; a++){
            void * shr_ptr = mmap(0,mem_size, PROT_READ, MAP_SHARED, shm_fd, (mem_size*a) );
            
            if(shr_ptr == MAP_FAILED){
                    perror(NULL);
                    shm_unlink(shm_name);
                    return errno;
            }
            //parcurgem vectorul
            int *shm_int = (int*) shr_ptr;

            int index = 0;
            printf("%d: ", shm_int[index++] );
            if(shm_int[index] == 1){
                printf("1");
                //caz special pentru 1
            }

            while(shm_int[index] != 1){
                printf("%d ", shm_int[++index] );

            }
            printf("\n");


            munmap(shr_ptr, mem_size);
        }



    shm_unlink(shm_name);
     
    }

}