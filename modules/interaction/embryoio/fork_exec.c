#include <unistd.h>
#include <sys/wait.h>

void pwncollege()
{
	return;
}

int main(int argc, char **argv)
{
	char *challenge_file = "/challenge/embryoio_level31";
	int child_pid = fork();
	if(child_pid == 0)
		execve(challenge_file, NULL, NULL);
	else
		waitpid(child_pid, NULL, 0);
}

