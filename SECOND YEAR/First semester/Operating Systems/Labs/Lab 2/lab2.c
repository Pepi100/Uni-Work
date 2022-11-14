#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {

    if(argc <2){
        printf("Numar invalid de argumente\n");
        return EINVAL;
    }


    struct stat informatii;
    stat(argv[1], &informatii);

    printf("Fisierul %s are dimensiunea %s", argv[1], informatii.st_size);
    
    
    

	int fd_scriere = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);


    if(fd_scriere <0){
        perror("eroare la deschidere fisier\n");
        return 1;
    }


	printf("Descriptorul pentru %s este %d\n", argv[1], fd_scriere);

	char *buffer = "Hello, world!";
	int nr_write = write(fd_scriere, buffer, strlen(buffer));

    if (nr_write!=strlen(buffer)){
        perror("Eroare la scriere\n");
        close(fd_scriere);

    }

	printf("Am scris in %s textul %s\n", argv[1], buffer);
    close(fd_scriere);



    //citire
	
    int fd_citire = open(argv[1], O_RDONLY);

    if(fd_citire <0){
        perror("Eroare la deschidere fisier\n");
        return 1;
    }
    char buffer2[20];
	int nr_read = read(fd_citire, buffer2, 20);
	 printf("Am citit din %s textul %s de lungime %d", argv[1], buffer2, nr_read);
	 close(fd_citire);
	return 0;
}