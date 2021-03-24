#include <stdio.h> 
#include <stdlib.h>
int main() 
{ 
    int* ptr = (int *) malloc(sizeof(int));
    printf("Ptr: %d\n", (*ptr)); 
    return 0;
}