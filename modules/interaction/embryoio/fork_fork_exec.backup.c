#include <unistd.h>
#include <sys/wait.h>
#include <glob.h>

void pwncollege()
{
	return;
}

int main(int argc, char **argv)
{
	glob_t globbuf;
	glob("/challenge/embryoio_level*", GLOB_ERR, NULL, &globbuf);
	if (globbuf.gl_pathc != 1)
		return 1;
	char *executable = globbuf.gl_pathv[0];

	pid_t pid = fork();
	if(pid == 0)
	{
		int pipe_fds[2];
		pipe(pipe_fds);

		pid = fork();
		if(pid == 0)
		{
			dup2(pipe_fds[0], 0);
			close(pipe_fds[1]);
			char *cmd[] = {"/usr/bin/cat", NULL};
			execve(cmd[0], cmd, NULL);
		}
		else
		{
			dup2(pipe_fds[1], 1);  // Stdout to the right/write side of the pipe.
			close(pipe_fds[0]);    // Close the read side.
			char *cmd[] = {executable, NULL};
			execve(cmd[0], cmd, NULL);
			waitpid(pid, NULL, 0);
		}
	}
	else
		waitpid(pid, NULL, 0);

	globfree(&globbuf);

	return 0;
}
