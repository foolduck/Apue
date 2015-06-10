/*************************************************************************
    > File Name: vfork.c
    > Author: guomingwei
    > Mail: mwguo07@163.com 
    > Created Time: Tue 09 Jun 2015 03:46:47 PM CST
 ************************************************************************/

#include <stdio.h>
#include <apue.h>

int globvar = 6;

int main(int argc, char **argv)
{
	int var;
	pid_t pid;

	var = 88;
	printf("before vfork :\n");
	if((pid = vfork()) < 0)
		err_sys("vfork error");
	else if(pid == 0)
	{
		globvar ++;
		var ++;
		exit(0);
	}
	printf("pid = %ld, globvar = %d, var = %d\n", (long)getpid(), globvar, var);
	_exit(0);
}
