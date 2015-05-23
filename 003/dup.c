#include <apue.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char** argv)
{
	int fd1, fd2, fd3;
	if((fd1 = open("dup.txt", O_RDWR | O_CREAT)) < 0)
		err_sys("open error 1");

	if((fd2 = open("dup_test.c", O_RDWR | O_CREAT)) < 0)
		err_sys("open error 2");
/*
	if((fd3 = open("hole_file.c", O_RDWR | O_CREAT)) < 0)
		err_sys("open error 3");*/
	fd3 = dup2(fd1, 0);
	int y = dup(fd2);
	int z = dup(fd3);
	
	printf("call dup :  %d	%d	%d	%d	%d	%d\n", fd1, fd2, fd3, -1, y, z);
	exit(0);
}


/**
  *the function is to return the minimum fd which can be used.
  */
