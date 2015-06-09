/*************************************************************************
    > File Name: echoarg.c
    > Author: guomingwei
    > Mail: mwguo07@163.com 
    > Created Time: Sat 06 Jun 2015 03:23:51 PM CST
 ************************************************************************/

#include <stdio.h>
#include <apue.h>

int main(int argc, char **argv)
{
	int i;
	for(i = 0; argv[i] != NULL; ++i)
	{
		printf("argv[%d] : %s\n", i, argv[i]);
	}
	exit(0);
}
