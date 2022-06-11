int main(int argc, char **argv)
{
    char buf[1024];
    int n;
    int fd = argc == 1 ? 0 : open(argv[1], 0);

    //puts("HAHAH!");
    while ((n = read(fd, buf, 1024)) > 0 && write(1, buf, n) > 0);
    //while ((n = syscall(0, fd, buf, 1024)) > 0 && syscall(1, 1, buf, n) > 0);

    return 0;
}
