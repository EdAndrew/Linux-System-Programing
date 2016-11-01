#include <fcntl.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <errno.h> 


int main()
{
	int ret;
	ret = symlink("/home/ed/code/lsp/link/text", "/home/ed/code/lsp/link/text.symlink");
	if (ret)
		perror("symlink");
}
