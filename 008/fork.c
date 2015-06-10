/*************************************************************************
    > File Name: fork.c
    > Author: guomingwei
    > Mail: mwguo07@163.com 
    > Created Time: Tue 09 Jun 2015 03:26:18 PM CST
 ************************************************************************/

#include <stdio.h>
#include <apue.h>

int globvar = 6;
char buf[] = "a write to stdout\n";

int main(int argc, char **argv)
{
	int var;
	pid_t pid;
	var = 88;
	if(write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
		err_sys("write error");
	printf("befor fork: \n");

	if((pid = fork()) < 0)
		err_sys("fork error");
	else if(pid == 0)
	{
		globvar ++;
		var ++;
	}
	else
		sleep(2);

	printf("pid = %ld, globvar = %d, var = %d\n", (long)getpid(), globvar, var);
	_exit(0);
	//exit(0);
}
