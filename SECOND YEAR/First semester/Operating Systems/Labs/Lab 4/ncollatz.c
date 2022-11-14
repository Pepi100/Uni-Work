#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include<stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){


	if(argc <2){
        printf("Numar invalid de argumente\n");
        return EINVAL;
    }

	int n;
	pid_t parent_pid = getpid();
	pid_t pid;
	
	printf("Parinte : %d\n", getpid());

	for(int a=1;a<argc;){
		pid = fork();

		

		n=atoi(argv[a]);


		

		if(pid<0){
		perror("Ceva nu e bine");
		return errno;

		}else if(pid==0){
			
			if(argv[1][0] < '0' || argv[1][0] > '9'){

				printf("Argument invalid.\n");
				return EINVAL;
			}

			printf("%d: ", n);

			while(n!=1){
				printf("%d ", n);
				if(n%2==0) n/=2;
				else n=3*n+1;
			}

			printf("1\n");
			break;
		}else{
		wait(NULL);

		printf("Parinte: Am id %d! Copilul meu cu id %d a terminat!\n",getpid(), pid);
		a++;
		// wait(NULL);
		}

	}
	if(getpid() == parent_pid) {
		printf("Consola: Am id %d! Copilul meu cu id %d a terminat! \n",getpid(), pid);
	}



return 0;
}


