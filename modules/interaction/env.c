int main(int argc, char **argv, char **envp)
{
    for (int i = 0; envp[i] != 0; i++)
        puts(envp[i]);
    return 0;
}
