#include <apue.h>
#include <sys/utsname.h>

int main()
{
	struct utsname uts;
	if((uname(&uts)) == -1)
		err_sys("uname error");
	printf("sysname:%s\nnodename:%s\nrelease:%s\nversion:%s\nmachine:%s\n", uts.sysname, uts.nodename, uts.release, uts.version, uts.machine);
	exit(0);
}
