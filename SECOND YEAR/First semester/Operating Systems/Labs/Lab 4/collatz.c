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

	if(argv[1][0] < '0' || argv[1][0] > '9'){

		printf("Argument invalid.\n");
        return EINVAL;
	}

	n=atoi(argv[1]);


	pid_t pid = fork();

	if(pid<0){
	perror("Ceva nu e bine");
	return errno;

	}else if(pid==0){
		printf("%d: ", n);

		while(n!=1){
			printf("%d ", n);
			if(n%2==0) n/=2;
			else n=3*n+1;
		}

		printf("1\n");
	}else{
	wait(NULL);

	printf("Parinte: Am id %d! Copilul meu are id %d!\n",getpid(), pid);
	// wait(NULL);
	}




return 0;
}


/*
tema
1. Face unproces cu fork
 Afisam fisierele din directorul curent, ls practic


2. Sa munceasca copilul


*/