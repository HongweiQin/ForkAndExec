#include <unistd.h>
#include <linux/types.h>
#include <stdio.h>

int main()
{
	pid_t ret;
	printf("This is the main process\n");
	ret = fork();
	if(ret)
	{
		char *const agv[] = {"exec1",NULL};
		printf("In the child process\n");
		execve("exec1",agv,NULL);
		printf("child1 exec failed\n");
	}
	else
	{
		printf("In the parent process\n");
		execve("exec2",NULL,NULL);
		printf("parent exec failed\n");
	}
	return 0;
}
