#include <apue.h>

int main(int argc, char **argv)
{
	printf("the pid of this process is %ld\n", (long)getpid());
	exit(0);
}
