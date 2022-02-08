#include "minitalk.h"
#include <stdio.h>

void  ft_putstr(char *c)
{
  int i = 0;
  while (c[i] != '\0')
  {
    write(1, &c[i], 1);
    i++;
  }
}

void sig_handler(int signum)
{

  ft_putstr("\nInside handler function\n");
}

int main()
{
  int pid;
	struct sigaction sa;

	sa.sa_handler = sig_handler;
	sa.sa_flags = SA_SIGINFO;
  pid = (int)getpid();


  ft_putstr(ft_itoa(pid));
	sigaction(SIGUSR1, &sa, NULL); 

  while (1);
  return 0;
}
