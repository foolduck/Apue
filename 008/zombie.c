/*************************************************************************
    > File Name: zombie.c
    > Author: guomingwei
    > Mail: mwguo07@163.com 
    > Created Time: Tue 09 Jun 2015 04:31:35 PM CST
 ************************************************************************/

#include <stdio.h>
#include <apue.h>

int main(int argc, char **argv)
{
	pid_t pid;
	printf("this is parent process, the pid of it is : %ld\n", (long)getpid());
	if((pid = fork()) < 0)
		err_sys("fork error");
	else if(pid == 0)	//child
	{
		printf("this is child process, the pid of it is : %ld\n", (long)getpid());
		exit(0);
	}
	else				//parent
	{
		for(;;)
			;
	}
	exit(0);
}
