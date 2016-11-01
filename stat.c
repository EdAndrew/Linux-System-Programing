#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	struct stat sb;
	int ret;

	if (argc != 2)
	{
		fprintf(stderr, "usage: %s <file>\n", argv[0]);
		return -1;	
	}
	
	ret = stat(argv[1], &sb);
	if (ret)
		perror("stat");

	printf("%s size is %d\n", argv[0], (int)sb.st_size);
	
}
