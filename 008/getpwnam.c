#include <apue.h>
#include <stdlib.h>
#include <pwd.h>

int main(int argc, char **argv)
{
	struct passwd * pw;
	if(argc != 2)
		err_quit("usage : %s username", argv[0]);

	pw = getpwnam(argv[1]);
	if (!pw)
		err_quit("user %s is not exist\n", argv[1]);
	printf("pw->pw_name = %s\n", pw->pw_name);
	printf("pw->pw_passwd = %s\n", pw->pw_passwd);
	printf("pw->pw_uid = %d\n", pw->pw_uid);
	printf("pw->pw_gid = %d\n", pw->pw_gid);
	printf("pw->pw_gecos = %s\n", pw->pw_gecos);
	printf("pw->pw_dir = %s\n", pw->pw_dir);
	printf("pw->pw_shell = %s\n", pw->pw_shell);
	exit(0);
}
