#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>

int main()
{
	int c1, c2;
	FILE *fp;

	fp = fdopen(0, "r");
	c1 = fgetc(fp);
	ungetc(c1, fp);
	c2 = fgetc(fp);
	printf("%c\n", c1);	
	printf("%c\n", c2);	
}
