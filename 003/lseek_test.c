#include <apue.h>

int main(int argc, char **argv)
{
	if(lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
		printf("cannot lseek\n");
	else
		printf("lseek ok\n");

	exit(0);
}

