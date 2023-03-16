#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>

int main () {
	pid_t pidB, pidC;
	int status;
	int m;
	int buffer;
	int fd;
	pidB = fork();
	if (pidB==0) {
		printf("Mi pid es %d y el de mi padre es %d\n", getpid(), getppid());
		execl("procesoB","",NULL);
		return 3;
	} //end if
	
	pidC = fork();
	if (pidC==0) {
		sleep(3);
		printf("Mi pid es %d y el de mi padre es %d\n", getpid(), getppid());
		return 0;
	} //end if
	
	waitpid(pidB,&status,0);
	if (WIFEXITED(status)) {
		printf("El valor de regreso de B es: %d\n", WEXITSTATUS(status));
		fd = open("enteros.txt",0);
		for (int i = 0; i<1001; i++) {
		m = read(fd, &buffer,sizeof(int));
		printf("%d	", buffer);
		} //end for
		close(fd);
	} //end if
	return 0;
} //end main
