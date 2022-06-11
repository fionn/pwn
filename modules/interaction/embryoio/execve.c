#include <unistd.h>

int main(int argc, char **argv)
{
    // No arguments, no environment
    execve(argv[1], NULL, NULL);
}

