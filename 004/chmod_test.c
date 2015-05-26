/*************************************************************************
    > File Name: chmod_test.c
    > Author: guomingwei
    > Mail: mwguo07@163.com 
    > Created Time: Tue 26 May 2015 10:17:34 PM CST
 ************************************************************************/

#include <apue.h>

int main(int argc, char** argv)
{
	struct stat statbuf;
	/* trun on set-group-ID and trun off group-execute  */

	if(stat("foo", &statbuf) < 0)
		err_sys("stat error for foo");
	if(chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
		err_sys("chmod error for foo");

	/* set absolute mode to "rw-r--r--" */
	if(chmod("bar", S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IROTH) < 0)
		err_sys("chmod error for bar");

	exit(0);
}
