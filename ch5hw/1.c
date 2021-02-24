#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
    int x = 100;
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        x += 10;
        printf("You are in child process. The value of x:= %i\n",x);
    } else {
        // parent goes down this path (original process)
        printf("hello, I am parent of %d (pid:%d)\n",
	       rc, (int) getpid());
        x += 20;
        printf("Your parent process updated the x value, and now x:= %i\n",x);
    }
    return 0;
}

//The child process will also initially have the variable x with the same value of 100. The modifications done by parent process will be 
//limited to parent, same for the child.