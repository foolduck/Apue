#include <apue.h>
#include <sys/wait.h>

char *envi_init[] = { "USER=unknow", "PATH=/tmp", NULL };

int main(int argc, char **argv)
{
	pid_t pid;
	int ret;
	if((pid = fork()) < 0)
		err_sys("fork error");
	else if(pid == 0)
	{		
		printf("the first child's pid is :%d\n", getpid());
		if(execle("/usr/bin/echoall", "echoall", "myargs1", "this is my second arg", (char*)0, envi_init) < 0)
			err_sys("execle error");
	}

	if(waitpid(pid, NULL, 0) < 0)
		err_sys("wait error");
	
	if((pid = fork()) < 0)
		err_sys("fork error");
	else if(pid == 0)
	{
		printf("the second child's pid is :%d\n", getpid());
		if(execlp("echoall", "echoall", "I have only one arg", (char*)0) < 0)
	
			err_sys("execle error");
	}
	
	ret = wait(NULL);
	printf("ret=%d\n", ret);
	exit(0);
}
