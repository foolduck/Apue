/*************************************************************************
    > File Name: nozombie.c
    > Author: guomingwei
    > Mail: mwguo07@163.com 
    > Created Time: 2015年06月09日 星期二 21时55分55秒
 ************************************************************************/

#include <stdio.h>
#include <apue.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	pid_t pid;
	if((pid = fork()) < 0)
		err_sys("fork error");
	else if(pid == 0)
	{
		if((pid = fork()) < 0)
			err_sys("fork error");
		else if(pid > 0)
			exit(0);
		else
		{
			sleep(2);
			printf("second child, parent pid = %ld\n", (long)getppid());
			exit(0);
		}
	}

	if(waitpid(pid, NULL, 0) != pid)
		err_sys("waitpid error");

	exit(0);
}
