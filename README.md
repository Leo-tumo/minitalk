# minitalk
![](https://github.com/hanshazairi/42-minitalk/workflows/norminette/badge.svg)

### The purpose of this project is to code a small data exchange program using UNIX signals.
We have to create a communication program in the form of a client and a server.
- The server must be started first. After its launch, it has to print its PID.
- The client takes two parameters:
  -  The server PID.
  -  The string to send.
- The client sends the string passed as a parameter to the server.
Once the string has been received, the server prints it.

### Used functions:

- [`malloc`](https://man7.org/linux/man-pages/man3/free.3.html)
- [`free`](https://man7.org/linux/man-pages/man3/free.3.html)
- [`write`](https://man7.org/linux/man-pages/man2/write.2.html)
- [`getpid`](https://man7.org/linux/man-pages/man2/getpid.2.html)
- [`sigemptyset`](https://man7.org/linux/man-pages/man3/sigsetops.3.html)
- [`sigaction`](https://man7.org/linux/man-pages/man2/sigaction.2.html)
- [`kill`](https://man7.org/linux/man-pages/man2/kill.2.html)
- [`usleep`](https://man7.org/linux/man-pages/man3/usleep.3.html)
- [`exit`](https://man7.org/linux/man-pages/man3/exit.3.html)
