#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int fop;
    fop = open("output.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);

    if(!fork())
    {
        write(fop, "child writes", 17);
        _exit(0);
    }
    else
    {
        wait(NULL);
        write(fop, "parent writes", 18);
        close(fop);
    }
}

/*
Yes, When a fork call happens the fop value in both processes is the same. The fop value is 
nothing but a reference in both programs for the file description. So Whatever they 
try to do using fop, happens on the same File description. In above code, Parent wait for child to 
complete, so child writes, and then parent writes on the same file. Parent closes 
the descriptor.
*/
