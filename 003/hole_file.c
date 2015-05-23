#include <apue.h>
#include <fcntl.h>

char buf1[] = "ABCDEFGHIJK";
char buf2[] = "abcdefghijk";

int main(int argc, char **argv)
{
	int fd;
	if((fd = creat("file.hole", FILE_MODE)) < 0)
		err_sys("creat error");

	if(write(fd, buf1, 11) != 11)
		err_sys("buf1 write error");

	if(lseek(fd, 186568, SEEK_SET) == -1)
		err_sys("lseek error");

	if(write(fd, buf2, 11) != 11)
		err_sys("buf2 write error");

	exit(0);

}
