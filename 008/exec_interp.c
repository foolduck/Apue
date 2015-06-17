#include <apue.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	pid_t pid;
	int ret;
	if((pid = fork()) < 0)
		err_sys("fork error");
	else if(pid == 0)
	{
		printf("the pid of child is : %d\n", getpid());
		if(execlp("/home/scut/git/Apue/008/testinterp", "testinterp", "myarg1", "MYARG2", (char *)0) < 0)
			err_sys("execle error");
	}
	ret = waitpid(pid, NULL, 0);
	if(ret < 0)
		err_sys("waitpid error");
	exit(0);
}


