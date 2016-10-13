#include <stdio.h>
#include <sys/mman.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	char *addr;
	int fd;
	struct stat sb;
	
	fd = open("/home/ed/code/lsp/file", O_RDWR);
	if (fd < 0)
		perror("open");

	if (fstat(fd, &sb) == -1)
		perror("fstat");	

	addr = (char *)mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE | PROT_WRITE, MAP_PRIVATE, fd, 0);	
	if (addr == MAP_FAILED)
		perror("mmap");
	
	printf("%s", addr);
	addr[0] = 'y';
	printf("%s", addr);
	if (msync(addr, sb.st_size, MS_SYNC) == -1)
		perror("msync");

	if (munmap(addr, sb.st_size) == -1)
		perror("munmap");

	//printf("%c\n", addr[0]); //there is segment fault
	//write(1, addr, 1);	//there is no problem, but nothing happen
	
	close(fd);	
	return 0;
}

