#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>

int main()
{
	int ret, n;
	fd_set set;
	char buf[1024];
	
	struct timeval timeout;
	timeout.tv_sec = 5;
	timeout.tv_usec = 0;

	FD_ZERO(&set);
	FD_SET(0, &set);
	ret = select(1, &set, NULL, NULL, &timeout);
	if (ret == -1)
		perror("select");
	else if (ret == 0 )
		printf("no thing.\n");
	else
	{
		if (FD_ISSET(0, &set))
		{
			n = read(STDIN_FILENO, buf, 1024);	
			write(STDOUT_FILENO, buf, n);
		}
	}			
		
}
