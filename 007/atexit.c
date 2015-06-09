/*************************************************************************
    > File Name: atexit.c
    > Author: guomingwei
    > Mail: mwguo07@163.com 
    > Created Time: Sat 06 Jun 2015 03:00:48 PM CST
 ************************************************************************/

#include <stdio.h>
#include <apue.h>

static void my_exit1(void);
static void my_exit2(void);

int main(int argc, char **argv)
{
	if(atexit(my_exit2) != 0)
		err_sys("can't register my_exit2'");
	if(atexit(my_exit1) != 0)
		err_sys("can't register my_exit1'");
	if(atexit(my_exit1) != 0)
		err_sys("can't register my_exit1'");

	printf("main is done\n");
	return 0;
}


static void my_exit1(void)
{
	printf("first exit handler\n");
}


static void my_exit2(void)
{
	printf("second exit handler\n");	
}

