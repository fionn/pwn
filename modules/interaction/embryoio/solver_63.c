#include <unistd.h>
#include <sys/wait.h>
#include <glob.h>

void pwncollege()
{
	return;
}

int main(int argc, char *argv[])
{
	glob_t globbuf;
	glob("/challenge/embryoio_level*", GLOB_ERR, NULL, &globbuf);
	if (globbuf.gl_pathc != 1)
		return 1;
	char *executable = globbuf.gl_pathv[0];

    char which_rev[] = "/usr/bin/rev";

    int pipe_fds_p[2];
    int pipe_fds_q[2];

	pid_t pid;
	switch(pid = fork())
	{
		case 0: // Child process
            pipe(pipe_fds_q);
            switch(pid = fork())
            {
                case 0: // Child process
                    dup2(pipe_fds_q[0], 0);
                    close(pipe_fds_q[1]);
                    char *cmd_c[] = {which_rev, NULL};
                    execve(cmd_c[0], cmd_c, NULL);
                default:
                    pipe(pipe_fds_p);
                    switch(pid = fork())
                    {
                        case 0: // Child process
                            dup2(pipe_fds_p[0], 0);
                            dup2(pipe_fds_q[1], 1);
                            close(pipe_fds_p[1]);
                            char *cmd_c[] = {which_rev, NULL};
                            execve(cmd_c[0], cmd_c, NULL);
                        default:
                            dup2(pipe_fds_p[1], 1);  // Stdout to the right/write side of the pipe.
                            close(pipe_fds_p[0]);    // Close the read side.
                            char *cmd_p[] = {executable, NULL};
                            execve(cmd_p[0], cmd_p, NULL);
                            waitpid(pid, NULL, 0);
                    }
            }
		default:
			waitpid(pid, NULL, 0);
	}

	globfree(&globbuf);

	return 0;
}
