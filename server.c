#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include <stdlib.h>

static int	nbrlen(int nbr)
{
	int i;

	i = (nbr <= 0) ? 1 : 0;
	if (nbr < 0)
		nbr *= -1;
	while (nbr)
	{
		nbr /= 10;
		++i;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		len;

	nbr = n;
	len = nbrlen(nbr);
	if (!(str = malloc(sizeof(unsigned char) * (len + 1))))
		return (NULL);
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	if (nbr == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (nbr)
	{
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
		--len;
	}
	return (str);
}

void sig_handler(int signum)
{

  printf("\nInside handler function\n");
}
void  ft_putstr(char *c)
{
  int i = 0;
  while (c[i] != '\0')
  {
    write(1, &c[i], 1);
    i++;
  }
}


int main()
{
  int pid;

  pid = (int)getpid();

  ft_putstr(ft_itoa(pid));

  printf("\n%d\n", pid);
  signal(SIGINT,sig_handler); // Register signal handler
  for(int i=1;;i++){    //Infinite loop
    printf("%d : Inside main function\n",i);//
    sleep(1);
  }
  return 0;
}
