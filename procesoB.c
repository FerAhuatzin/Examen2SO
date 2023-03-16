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
	int fd;
	int n;
	int buffer;
	fd = creat("enteros.txt",777);
	for (int i = 0; i<1001; i++) {
		buffer = i;
		n = write(fd, &buffer,sizeof(int));
	} //end for
	close(fd);
	return 3;
} //end main
