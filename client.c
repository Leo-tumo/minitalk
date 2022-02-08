#include "minitalk.h"
#include <stdio.h>
int main(int argc, char **argv)
{
pid_t pid;

    if(argc > 1)
        pid = (pid_t)atoi(argv[1]);

    printf("%d\n", pid);
    kill(pid, SIGUSR1);
    printf("signal sent");
} 