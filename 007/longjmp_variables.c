/*************************************************************************
    > File Name: longjmp_variables.c
    > Author: guomingwei
    > Mail: mwguo07@163.com 
    > Created Time: Mon 08 Jun 2015 04:50:49 PM CST
 ************************************************************************/

#include <stdio.h>
#include <setjmp.h>
#include <apue.h>

static void f1(int, int, int, int);
static void f2(void);

static jmp_buf jmpbuffer;
static int globval;

int main()
{
	int autoval;
	register int regival;
	volatile int volaval;
	static int statval;
	globval = 1;
	autoval = 2;
	regival = 3;
	volaval = 4;
	statval = 5;


	if(setjmp(jmpbuffer) != 0)
	{
		printf("after longjmp :\n");
		printf("globval = %d, autoval = %d, regival = %d, volaval = %d,"
			"statval = %d\n", globval, autoval, regival, volaval, statval);
	exit(0);
	}
	globval = 95;
	autoval = 96;
	regival = 97;
	volaval = 98;
	statval = 99;
	f1(autoval, regival, volaval, statval);
	exit(0);
}


void f1(int i, int j, int k, int l)
{
	printf("in f1 :\n");
	printf("globval = %d, autoval = %d, regival = %d, volaval = %d,"
		"statval = %d\n", globval, i, j, k, l);
	f2();
}


void f2()
{
	longjmp(jmpbuffer, 2);
}



