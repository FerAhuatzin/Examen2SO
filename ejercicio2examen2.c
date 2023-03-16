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
	pid_t pidD, pidE, pidF;
	int status;
	pidD = fork();
	if (pidD == 0) {
		return 2;
	} //end if
	pidE = fork ();
	if (pidE==0) {
		return 13;
	} //end if
	pidF = fork ();
	if (pidF==0) {
		return 14;
	} //end if
	
	float res;
	waitpid(pidD,&status,0);
	res = ((float)WEXITSTATUS(status)*2.0)-1.0;
	waitpid(pidF,&status,0);
	res = res + ((float)WEXITSTATUS(status)/1000.0);
	waitpid(pidE,&status,0);
	res = res + (((float)WEXITSTATUS(status)+3.0)/1000.0);
	printf("Valor de res es: %f",res);
	return 0;
} //end main
