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
	int ret;
	pid_t pid;

	var = 88;
	printf("before vfork :\n");
	if((pid = vfork()) < 0)
		err_sys("vfork error");
	else if(pid == 0)
	{
		globvar ++;
		var ++;
		fclose(stdout);
		exit(0);
	}
	ret = printf("pid = %ld, globvar = %d, var = %d\n", (long)getpid(), globvar, var);
	if(ret != -1)
		printf("stdout has not been closed, ret = %d\n", ret);
	exit(0);
}
