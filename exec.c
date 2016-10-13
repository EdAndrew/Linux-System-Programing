#include <unistd.h>
#include <errno.h>
#include <stdio.h>

int main()
{
	int ret;
	ret = execl("/usr/bin/vim", "vim", NULL);
	if (ret == -1)
		perror("execl");
}
