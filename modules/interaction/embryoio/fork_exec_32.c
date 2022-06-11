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
	char *cmd[] = {executable, NULL};
	char *env[] = {"lggijl=myccyeeucv", NULL};


	int child_pid = fork();

	if(child_pid == 0)
		execve(cmd[0], cmd, env);
	else
		waitpid(child_pid, NULL, 0);

	globfree(&globbuf);
	return 0;
}
