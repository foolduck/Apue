/*************************************************************************
    > File Name: setjmp_longjmp.c
    > Author: guomingwei
    > Mail: mwguo07@163.com 
    > Created Time: Mon 08 Jun 2015 04:24:01 PM CST
 ************************************************************************/

#include <stdio.h>
#include <apue.h>
#include <setjmp.h>

jmp_buf jmpbuffer;
static void foo();
static void bar();

int main(int argc, char **argv)
{
	int flag;
	if((flag = setjmp(jmpbuffer)) == 0)
	{
	//	foo();
		bar();
	}
	else
	{		
		switch(flag)
		{
			case 1:
				printf("this is function foo\n");
				break;
			case 2:
				printf("this is function bar\n");
				break;
			default:
				printf("longjmp has't been called or longjmp error\n");
				break;
		}
		exit(0);
	}
	bar();
	exit(0);
}


void foo()
{
	printf("foo\n");
	longjmp(jmpbuffer, 1);
}


void bar()
{
	printf("bar\n");
	longjmp(jmpbuffer, 2);
}
