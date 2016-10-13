#include <stdio.h>
#include <stdlib.h>

int fun()
{
	exit(EXIT_SUCCESS);
	return 0;
}

int main()
{
	printf("before fun()");
	fun();
	printf("after fun()");
}
