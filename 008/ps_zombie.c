#include <apue.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	int status;
	if((pid = fork()) < 0)
		err_sys("fork error");
	else if(pid == 0)
		exit(0);
	sleep(1);
	char buf[1024];       
	sprintf(buf, "ps -lea | grep %d", pid);
	if((status = system(buf)) == -1)
		err_sys("system error");
	exit(0);
}

