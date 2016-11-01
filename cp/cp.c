#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MaxSize 1024

int main(int argc, char *argv[])
{
	char buf[MaxSize];
	int src, des, n;

	if (argc != 3){
		fprintf(stderr, "usage: %s <src> <des>\n", argv[0]);
		return -1;
	}

	if ((src = open(argv[1], O_RDONLY)) == -1){
		perror("open src");
		return -1;
	}

	if ((des = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664)) == -1){
		perror("open des");
		return -1;
	}

	while (n = read(src, buf, MaxSize)){
		if (write(des, buf, n) != n){
			perror("write");
			return -1;
		}
	}

	close(src);
	close(des);
	return 0;		
}


















