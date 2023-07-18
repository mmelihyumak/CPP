#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char	**ft_split(const char *s, char c);

int main(int argc, char **argv, char **envp)
{
	char cmd1[] = "/bin/ls";
	char **args1 = ft_split(cmd1, ' ');

	char cmd2[] = "/usr/bin/wc";
	char **args2 = ft_split(cmd2, ' ');

	char cmd3[] = "/usr/bin/wc -l";
	char **args3 = ft_split(cmd3, ' ');

	//int fd = open("outfile", O_CREAT | O_TRUNC | O_RDWR, 0777);
	//int fdd = open("infile", O_RDONLY);

	int fd1[2];
	int fd2[2];

	pipe(fd1);
	pipe(fd2);

	int pid1 = fork();
	if (pid1 == 0)
	{
		dup2(fd1[1], 1);
		close(fd1[0]);
		close(fd1[1]);
		close(fd2[0]);
		close(fd2[1]);
		execve(args1[0], args1, envp);
	}
	int pid2 = fork();
	if (pid2 == 0)
	{
		dup2(fd1[0], 0);
		dup2(fd2[1], 1);
		close(fd1[1]);
		close(fd1[0]);
		close(fd2[1]);
		close(fd2[0]);
		execve(args2[0], args2, envp);
	}
	int pid3 = fork();
	if (pid3 == 0)
	{
		dup2(fd2[0], 0);
		close(fd1[0]);
		close(fd1[1]);
		close(fd2[0]);
		close(fd2[1]);
		execve(args3[0], args3, envp);
	}
	close(fd1[0]);
	close(fd1[1]);
	close(fd2[0]);
	close(fd2[1]);
	printf("fd-> %d\n", open("outfile", O_CREAT | O_TRUNC | O_RDWR, 0777));
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	waitpid(pid3, NULL, 0);
}