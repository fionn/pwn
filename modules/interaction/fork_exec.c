#include <unistd.h>
#include <sys/wait.h>
#include <glob.h>

int main(int argc, char *argv[])
{
    glob_t globbuf;
    //glob("/challenge/embryoio_level*", GLOB_ERR, NULL, &globbuf);
    glob("/usr/bin/ls", GLOB_ERR, NULL, &globbuf);
    if (globbuf.gl_pathc != 1)
        return 1;

    char *executable = globbuf.gl_pathv[0];
    char *cmd[] = {executable, NULL};
    char *env[] = {"a=b", NULL};

    pid_t pid;
    switch(pid = fork())
    {
        case 0:   // child
            execve(cmd[0], cmd, env);
        default:  // parent
            waitpid(pid, NULL, 0);
    }

    globfree(&globbuf);
    return 0;
}
