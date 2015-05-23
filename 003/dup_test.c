#include <unistd.h>
#include <apue.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
	int fd;
	fd = open("test.txt", O_WRONLY | O_TRUNC);
	if (fd == -1)
		err_sys("open error");


	close(1);
	dup(fd);

	dup2(fd, 1);
	printf("hello test\n");
	exit(0);
}
