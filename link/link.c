#include <fcntl.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <errno.h> 


int main()
{
	int ret;
	ret = link("/home/ed/code/lsp/link/text", "/home/ed/code/lsp/link/text.link");
	if (ret)
		perror("link");
}
