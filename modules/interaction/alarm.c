int handler(int signal)
{
    puts("DING!");
    exit(1);
}

int main()
{
    alarm(3);
    signal(14, handler);
    while(1);
    //sleep(100000);
}
