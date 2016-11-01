#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	int ret;

	errno = 0;
	ret = getpriority(PRIO_PROCESS, 0);
	if (ret == -1 && errno != 0)
		perror("getpriority");
	printf("prio = %d\n", ret);

	nice(10);
	errno = 0;
	ret = nice(0);
	if (ret == -1 && errno != 0)
		perror("nice");
	printf("nice = %d\n", ret);
	
}
