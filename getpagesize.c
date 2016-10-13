#include <stdio.h>
#include <unistd.h>

int main()
{
	int pageSize;
	pageSize = sysconf(_SC_PAGESIZE);
	printf("%d\n", pageSize);	
	pageSize = getpagesize();
	printf("%d\n", pageSize);	
}
