int handler(int signal)
{
    printf("Got signal number %d!\n", signal);
}

int main()
{
    for (int i = 1; i <= 64; i++)
        signal(i, handler);
    while(1);
}
