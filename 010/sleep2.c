#include <apue.h>
#include <setjmp.h>
#include <signal.h>
#include <unistd.h>

static jmp_buf env_alrm;

unsigned int sleep2(unsigned int);
static void sig_int(int);

int main(int argc, char **argv)
{
	unsigned int unslept;
	if(signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("signal(SIGINT) error");
	unslept = sleep2(5);
	printf("sleep2 returned : %u\n", unslept);
	exit(0);
}

static void sig_alrm(int signo)
{
	longjmp(env_alrm, 1);
}


unsigned int sleep2(unsigned int seconds)
{
	if(signal(SIGALRM, sig_alrm) == SIG_ERR)
		return seconds;
	if(setjmp(env_alrm) == 0)
	{
		alarm(seconds);
		pause();
	}
	return alarm(0);
}

static void sig_int(int signo)
{
	int i, j;
	volatile int k;

	printf("\nsig_int starting\n");
	for(i = 0; i < 300000000; i++)
		for(j = 0; j < 40000000000; j++)
			k += i*j;
	printf("sig_int finished\n");
}


