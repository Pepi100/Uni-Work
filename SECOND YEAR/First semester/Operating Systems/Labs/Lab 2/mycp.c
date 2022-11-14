#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {

    if(argc <3){
        printf("Numar invalid de argumente\n");
        return EINVAL;
    }

    char buffer[22];



	int f_initial = open(argv[1], O_RDONLY);
    int f_final = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);


    if(f_initial <0){
        perror("Eroare la deschidere fisier de citire\n");
        return errno;
    }

    if(f_final <0){
        perror("Eroare la deschidere fisier de scriere\n");
        return errno;
    }

    int nr_read = read(f_initial, buffer, 20);
    int nr_write = write(f_final, buffer, strlen(buffer));

    //citim cate 20 de caractere si le scriem in noul fisier
    //repetam procesul pana la o citire care a fost mai mica de 20

    while(nr_read == 20){

        nr_read = read(f_initial, buffer, 20);
        buffer[nr_read]='\0';
        nr_write = write(f_final, buffer, strlen(buffer));
    }

    
    close(f_initial);
    close(f_final);

	return 0;
}
