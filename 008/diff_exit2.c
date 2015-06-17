/*************************************************************************
    > File Name: diff_exit.c
    > Author: guomingwei
    > Mail: mwguo07@163.com 
    > Created Time: Tue 09 Jun 2015 07:08:00 PM CST
 ************************************************************************/

#include <stdio.h>
#include <apue.h>
#include <sys/wait.h>
#include <errno.h>

static void waitid_info(siginfo_t *infop)
{
	if(infop != NULL)
	{
		if(infop->si_code == CLD_EXITED)
			printf("normal termination, exit status = %d\n", infop->si_status);
		else if(infop->si_code == CLD_KILLED)
			printf("abnormal termination, signal number = %d\n", infop->si_signo);
		else if(infop->si_code == CLD_DUMPED)
			printf("abnormal termination, signal number = %d(core file generated)\n", infop->si_signo);
	}
}


int main(int argc, char **argv)
{
	pid_t pid;
	int status;
	siginfo_t infop;
//
	if((pid = fork()) < 0)
		err_sys("fork error");
	else if(pid == 0)
		exit(7);

	if(waitid(P_PID, (id_t)pid, &infop, WEXITED | WNOWAIT | WSTOPPED) != 0)
		err_sys("waitid error");

	waitid_info(&infop);

	if((pid = fork()) < 0)
		err_sys("fork error");
	else if(pid == 0)
		abort();

	if(waitid(P_PID, (id_t)pid, &infop, WEXITED | WNOWAIT | WSTOPPED) != 0)
		err_sys("waitid error");
	
	waitid_info(&infop);
//
	if((pid = fork()) < 0)
		err_sys("fork error");
	else if(pid == 0)
		status /= 0;
	
	if(waitid(P_PID, (id_t)pid, &infop, WEXITED | WNOWAIT | WSTOPPED) != 0)
		err_sys("waitid error");

	waitid_info(&infop);

	exit(0);
}



